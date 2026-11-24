class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 2, i = 0;
        unordered_map<int, int> last;

        for (int j = 0; j < n; ++j) {
            vector<int> primes = primeDivisors(nums[j]);
            for (int p : primes)
                i = max(i, last.count(p) ? last[p] + 1 : 0), last[p] = j;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }

    vector<int> primeDivisors(int x) {
        vector<int> primes;
        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0) {
                primes.push_back(d);
                x /= d;
            }
            while (x % d == 0)
                x /= d;
        }
        if (x > 1)
            primes.push_back(x);
        return primes;
    }
};