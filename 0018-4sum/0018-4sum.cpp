typedef long long ll;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int lastI = INT_MIN;
        unordered_map<ll, int> cnt;
        for (auto& num : nums) {
            cnt[num]++;
        }
        for (int i = 0; i < n - 3; i++) {
            cnt[nums[i]]--;
            if (nums[i] != lastI) {
                int lastJ = INT_MIN;
                for (int j = i + 1; j < n - 2; j++) {
                    cnt[nums[j]]--;
                    if (nums[j] != lastJ) {
                        int lastK = INT_MIN;
                        for (int k = j + 1; k < n - 1; k++) {
                            cnt[nums[k]]--;
                            if (nums[k] != lastK) {
                                ll diff = (ll)target -
                                          ((ll)nums[i] + nums[j] + nums[k]);
                                if (cnt[diff] > 0) {
                                    ans.push_back(
                                        {nums[i], nums[j], nums[k], (int)diff});
                                }
                            }
                            lastK = nums[k];
                        }
                        for (int k = j + 1; k < n - 1; k++) {
                            cnt[nums[k]]++;
                        }
                    }
                    lastJ = nums[j];
                }
                for (int j = i + 1; j < n - 2; j++) {
                    cnt[nums[j]]++;
                }
            }
            lastI = nums[i];
        }
        return ans;
    }
};

// Map, time: O(n^3), space: O(n + m)