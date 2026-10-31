class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();

        if (n < 2)
            return s[0] == '0' ? 0 : 1;
        vector<int> dp(n + 1, 0);

        int twoCharNum = stoi(s.substr(0, 2));

        if (twoCharNum < 10)
            return 0;

        if (twoCharNum <= 26)
            dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            twoCharNum = stoi(s.substr(i - 2, 2));
            int num = twoCharNum % 10;
            if (10 <= twoCharNum && twoCharNum <= 26 && num != 0)
                dp[i] = dp[i - 1] + dp[i - 2];
            else if (10 <= twoCharNum && twoCharNum <= 26)
                dp[i] = dp[i - 2];
            else if (num != 0)
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }
};