class Solution {
private:
    int gcd(int a, int b) {
        if (!b)
            return a;
        return gcd(b, a % b);
    }

public:
    int findGCD(vector<int>& nums) {
        int n = nums.size(), mx = INT_MIN, mn = INT_MAX;
        for (auto& num : nums)
            mx = max(mx, num), mn = min(mn, num);
        return gcd(mn, mx);
    }
};