class Solution {
private:
    void swap(vector<vector<int>>& arr, int fI, int fJ, int sI, int sJ) {
        int temp = arr[fI][fJ];
        arr[fI][fJ] = arr[sI][sJ];
        arr[sI][sJ] = temp;
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int left = 0, top = 0, right = n - 1, bottom = n - 1;
        int aLeft = 0, aRight = n - 1, aTop = n - 1, aBottom = 0;
        while (left < right && top < bottom) {
            aLeft = left, aBottom = bottom, aRight = right, aTop = top;
            while (aLeft < right) {
                swap(matrix, top, aLeft, aBottom, left);
                swap(matrix, aBottom, left, bottom, aRight);
                swap(matrix, bottom, aRight, aTop, right);
                aLeft++, aBottom--, aRight--, aTop++;
            }
            left++, right--, bottom--, top++;
        }
    }
};