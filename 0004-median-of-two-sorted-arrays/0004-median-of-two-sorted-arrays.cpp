typedef long long ll;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n, l = 0, r = nums1.size() - 1, half = (m + n) / 2;
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        while (1) {
            int mid = l + floor((r - l) / 2.0F);
            int p1_left = INT_MIN, p1_right = INT_MAX, p2_left = INT_MIN,
                p2_right = INT_MAX;

            if (0 <= mid && mid < m)
                p1_left = nums1[mid];

            if (0 <= mid + 1 && mid + 1 < m)
                p1_right = nums1[mid + 1];

            if (0 <= half - mid - 2 && half - mid - 2 < n)
                p2_left = nums2[half - mid - 2];

            if (0 <= half - mid - 1 && half - mid - 1 < n)
                p2_right = nums2[half - mid - 1];

            if (p1_right >= p2_left && p1_left <= p2_right) {
                if (total & 1) {
                    return min(p1_right, p2_right);
                }
                return (max(p1_left, p2_left) + min(p1_right, p2_right)) / 2.0F;
            } else if (p1_left > p2_right) {
                r = mid - 1;
            } else if (p2_left > p1_right) {
                l = mid + 1;
            }
        }
        return 0.0F;
    }
};

// Binary Search, time: O(log(max(m, n))), space: O(1)