class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> idx;
        for (auto& str : strs) {
            string tmp(str.begin(), str.end());
            sort(tmp.begin(), tmp.end());
            if (idx.count(tmp))
                ans[idx[tmp]].push_back(str);
            else
                ans.push_back({str}), idx[tmp] = ans.size() - 1;
        }
        return ans;
    }
};