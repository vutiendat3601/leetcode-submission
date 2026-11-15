typedef long long ll;
class Solution {
private:
    const int MOD = 1E9 + 7;

public:
    int numOfSubarrays(vector<int>& nums) {
        ll pref = 0, ans = 0, even = 1, odd = 0;
        for (auto& num : nums) {
            pref += num;
            if (pref & 1)
                ans += even, odd++;
            else
                ans += odd, even++;
            ans %= MOD;
        }
        return ans;
    }
};