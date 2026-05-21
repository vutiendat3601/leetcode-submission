class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        for (long i = 0; i <= x; i++) {
            if (i * i > x)
                return ans;
            ans = i;
        }
        return ans;
    }
};

// Brute Force, time: O(n), space: O(1)