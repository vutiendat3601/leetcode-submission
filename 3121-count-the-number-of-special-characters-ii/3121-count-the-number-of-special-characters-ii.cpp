class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> idx;
        int n = word.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if ('A' <= word[i] && word[i] <= 'Z') {
                if (!idx.count(word[i]))
                    idx[word[i]] = i;
            } else {
                idx[word[i]] = i;
            }
        }

        for (char c = 'A'; c <= 'Z'; c++)
            if (idx.count(c) && idx.count(c + 32) && idx[c] > idx[c + 32])
                ans++;

        return ans;
    }
};