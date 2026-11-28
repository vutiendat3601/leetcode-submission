class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> unq(nums.begin(), nums.end());
        for (auto& num : unq) {
            if (!unq.count(num - 1)) {
                int tmp = num, cnt = 1;
                while (unq.count(tmp + 1))
                    cnt++, tmp++;
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};