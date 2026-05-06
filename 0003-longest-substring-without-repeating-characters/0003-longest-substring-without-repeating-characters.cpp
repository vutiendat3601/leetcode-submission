class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = 0, r = 0, ans = 0;
        unordered_map<char, int> last_idx;
        while (r < n) {
            if (last_idx.count(s[r]) && last_idx[s[r]] >= l) {
                l = last_idx[s[r]] + 1;
            }
            last_idx[s[r]] = r;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

// Sliding Window, time: O(n), space: O(n)