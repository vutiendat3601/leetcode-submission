class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> group;

        for (auto& str : strs) {
            string des(str.begin(), str.end());
            sort(des.begin(), des.end()),
            group[des].push_back(str);
        }
        for (auto& [_, val] : group) 
            ans.push_back(val);
        
        return ans;
    }
};

// Hashing, time: O(n), space: O(n)