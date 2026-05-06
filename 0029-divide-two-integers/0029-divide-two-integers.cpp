typedef long long ll;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isNegative = (dividend > 0) ^ (divisor > 0);
        ll dvd = dividend >= 0 ? dividend : -(ll)dividend;
        ll dvs = divisor >= 0 ? divisor : -(ll)divisor;
        ll ans = 0;
        while (dvs <= dvd) {
            ll pow2 = (1LL << 31);
            ll res = dvs * pow2;
            int k = 30;
            while (res > dvd) {
                pow2 = 1LL << k;
                res = dvs * pow2;
                k--;
            }
            ans += pow2;
            dvd -= res;
        }
        return (int)(isNegative ? -ans : ans <= INT_MAX ? ans : INT_MAX);
    }
};