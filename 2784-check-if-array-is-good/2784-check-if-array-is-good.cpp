class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> cnt(n + 2, 0);
        for (auto& num : nums)
            if (num <= n)
                cnt[num]++;
            else
                return 0;
        for (int i = 1; i < n; i++)
            if (cnt[i] != 1)
                return 0;
        return cnt[n] == 2;
    }
};