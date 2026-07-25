class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unq(nums.begin(), nums.end());
        int ans = 0;
        for (auto& num : unq) {
            if (!unq.count(num - 1)) {
                int nxt = num + 1;
                while (unq.count(nxt))
                    nxt++;
                ans = max(ans, nxt - num);
            }
        }
        return ans;
    }
};