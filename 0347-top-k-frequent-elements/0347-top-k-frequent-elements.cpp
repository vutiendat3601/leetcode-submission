class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        vector<int> ans(k, 0);
        for (auto& num : nums)
            cnt[num]++;
        vector<pair<int, int>> sorted;
        for (auto& [k, v] : cnt)
            sorted.push_back({v, k});
        sort(sorted.rbegin(), sorted.rend());
        for (int i = 0; i < k; i++)
            ans[i] = sorted[i].second;
        return ans;
    }
};