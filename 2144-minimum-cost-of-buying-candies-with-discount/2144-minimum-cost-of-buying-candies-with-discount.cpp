class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size(), ans = cost[n - 1], i = n - 2, cnt = 1;
        while (i >= 0) {
            cnt++;
            if (cnt % 3)
                ans += cost[i];
            i--;
        }
        return ans;
    }
};