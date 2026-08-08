class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = 1;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= n; i++) {
            if (dp[i - 1]) {
                for (auto& word : words) {
                    if (i + word.size() - 1 <= n) {
                        string z = s.substr(i - 1, word.size());
                        if (words.count(z)) {
                            dp[i + word.size() - 1] = 1;
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};