class Solution {
public:
    double myPow(double x, int n) {
        if (!n || n == 1)
            return n ? x : 1;

        double tmp = 0;
        long ln = n;
        if (ln > 1) {
            tmp = myPow(x, n / 2), tmp *= tmp;
            if ((ln & 1L) > 0)
                tmp *= x;
        } else if (ln < 0) {
            tmp = myPow(x, -(n / 2)), tmp *= tmp;
            if ((-ln & 1L) > 0)
                tmp *= x;
            tmp = 1.0 / tmp;
        }
        return tmp;
    }
};