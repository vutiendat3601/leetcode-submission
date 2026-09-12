class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), k = minutes, ans = 0, l = 0, sum = 0,
            mxSum = 0;
        for (int i = 0; i < k; i++) {
            if (grumpy[i])
                sum += customers[i];
            ans += customers[i];
        }
        mxSum = sum;

        while (l + k < n) {
            if (grumpy[l])
                sum -= customers[l];

            if (grumpy[l + k])
                sum += customers[l + k];
            else
                ans += customers[l + k];

            if (sum > mxSum)
                ans -= mxSum, mxSum = sum, ans += mxSum;
                
            l++;
        }
        return ans;
    }
};