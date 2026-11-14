class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1, 1);

        for (int i = 1; i <= n; i++)
            factorial[i] = factorial[i - 1] * i;

        k--;

        vector<int> available;

        for (int i = 1; i <= n; i++)
            available.push_back(i);

        string ans = "";

        for (int i = 0; i < n; i++) {
            int f = factorial[n - i - 1], index = k / f;
            k %= f, ans += to_string(available[index]),
                available.erase(available.begin() + index);
        }

        return ans;
    }
};