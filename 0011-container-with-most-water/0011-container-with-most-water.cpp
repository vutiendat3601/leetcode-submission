class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1, ans = 0;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};

// 2-pointers, time: O(n), space: O(1)