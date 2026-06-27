typedef long long ll;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<ll> nextValues(1001, INT_MAX);
        vector<int> idx(1001, 0);
        for (int prime : primes)
            nextValues[prime] = prime;

        vector<int> p(n);
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            int next = *min_element(nextValues.begin(), nextValues.end());
            p[i] = next;
            for (int prime : primes)
                if (next == nextValues[prime])
                    idx[prime]++, nextValues[prime] = (ll)p[idx[prime]] * prime;
        }
        return p[n - 1];
    }
};