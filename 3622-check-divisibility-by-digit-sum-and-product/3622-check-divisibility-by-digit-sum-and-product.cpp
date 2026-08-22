class Solution {
public:
    bool checkDivisibility(int n) {
        int orig_n = n, p = 1, s = 0;
        while (n > 0)
            p *= n % 10, s += n % 10, n /= 10;
        return orig_n % (p + s) == 0;
    }
};