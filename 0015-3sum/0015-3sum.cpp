class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), last = INT_MIN;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] != last) {
                int target = 0 - nums[i];
                int l = i + 1, r = n - 1;
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        int j = r;
                        l++;
                        r--;
                        while (r > l && nums[r] == nums[j]) {
                            r--;
                        }
                    }
                }
            }
            last = nums[i];
        }
        return ans;
    }
};

// Sorting + 2-pointers, time: O(n.log(n)), space: O(1)