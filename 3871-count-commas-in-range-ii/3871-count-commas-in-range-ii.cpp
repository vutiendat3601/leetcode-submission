typedef long long ll;
typedef unsigned long long ull;

class Solution {
private:
    vector<ll> inc = {1000LL, 1000000LL, 1000000000LL, 1000000000000LL,
                      1000000000000000LL};

public:
    ll countCommas(ll n) {
        ll ans = 0, i = 0;
        while (i < 5) {
            if (inc[i] > n) {
                break;
            }
            ll numOfNumbers =
                min((ull)inc[i] * 1000 - inc[i], (ull)n - inc[i] + 1);
            int sz = to_string(inc[i]).size();
            ll numOfCommas = (sz - 1) / 3;
            ans += numOfCommas * numOfNumbers;
            i++;
        }
        return ans;
    }
};