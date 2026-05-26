class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> chs(word.begin(), word.end());
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++)
            if (chs.count(c) && chs.count(c - 32))
                ans++;
        return ans;
    }
};