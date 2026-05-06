typedef long long ll;

class Solution {
public:
    int reverse(int x) {
        int sign = x > -1 ? 1 : -1;
        ll tmp = (ll)x * sign, rev = 0;
        while (tmp > 0)
            rev *= 10, rev += tmp % 10, tmp /= 10;

        rev = sign * rev;
        return (rev < INT_MIN || rev > INT_MAX) ? 0 : rev;
    }
};