typedef long long ll;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        int orig = x;
        ll rev = 0;
        while (x)
            rev *= 10, rev += x % 10, x /= 10;
        return rev == orig;
    }
};