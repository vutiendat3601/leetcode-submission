class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        string ans = "";
        if (n < t.size())
            return ans;
        
        unordered_map<char, int> mt, mp;
        for (auto& c : t)
            mt[c]++;
        int l = 0, r = 0;
        while (r < n) {
            int i = 0;
            if (mt.count(s[r])) {
                mp[s[r]]++;
                while (!mt.count(s[l]) || mp[s[l]] - 1 >= mt[s[l]]) {
                    mp[s[l]]--;
                    l++;
                }
                while (i < t.size()) {
                    if (mp[t[i]] < mt[t[i]]) {
                        break;
                    }
                    i++;
                }
            }
            r++;
            if (i == t.size()) {
                ans = s.substr(l, r - l);
                break;
            }
        }
        while (r < n) {
            if (mt.count(s[r])) {
                mp[s[r]]++;
                while (!mt.count(s[l]) || mp[s[l]] - 1 >= mt[s[l]]) {
                    mp[s[l]]--;
                    l++;
                }
                if (r - l + 1 < ans.size()) {
                    ans = s.substr(l, r - l + 1);
                }
            }
            r++;
        }
        return ans;
    }
};

// Sliding Window + Counting, time: O(n), space: O(n)