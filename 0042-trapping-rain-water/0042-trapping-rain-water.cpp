class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> mxLeft(n, 0), mxRight(n, 0);
        for (int j = 1; j < n; j++){
            mxLeft[j] = max(mxLeft[j - 1], height[j - 1]);
            mxRight[n - 1 - j] = max(mxRight[n - j], height[n - j]);
        }
        for (int i = 0; i < n; i++) {
            int diff = min(mxLeft[i], mxRight[i]) - height[i];
            if (diff > 0)
                ans += diff;
        }
        return ans;
    }
};