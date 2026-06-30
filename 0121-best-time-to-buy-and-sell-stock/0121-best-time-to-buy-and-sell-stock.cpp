class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buy = prices[0];
        for (auto& price : prices)
            if (price >= buy)
                ans = max(ans, price - buy);
            else
                buy = min(buy, price);

        return ans;
    }
};