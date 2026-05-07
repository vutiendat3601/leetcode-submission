class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            vector<int> prev_days = {days[i] - 1, days[i] - 7, days[i] - 30};
            for (int j = 0; j < 3; j++) {
                int k = i;
                while (k >= 0 && days[k] > prev_days[j])
                    k--;
                dp[i] = min(dp[i], costs[j] + (k >= 0 ? dp[k] : 0));
            }
        }
        return dp[n - 1];
    }
};

// DP, time: O(n), space: O(n)