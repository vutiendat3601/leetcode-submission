class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), ans = 0;
        stack<int> st1, st2;
        vector<int> bl(n), br(n);
        for (int i = 0; i < n; i++) {
            bl[i] = i;
            while (!st1.empty() && h[st1.top()] >= h[i]) {
                bl[i] = bl[st1.top()];
                st1.pop();
            }
            st1.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            br[i] = i;
            while (!st2.empty() && h[st2.top()] >= h[i]) {
                br[i] = br[st2.top()];
                st2.pop();
            }
            st2.push(i);
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, (br[i] - bl[i] + 1) * h[i]);
        }
        return ans;
    }
};

// Stack, Splitting 2 parts, checking left part, checking right part, time: O(n)