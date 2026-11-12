class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (auto num : nums) {
            int mx = 0, cnt = 0;
            while (num > 0)
                mx = max(mx, num % 10), num /= 10, cnt++;
            ans += stoi(string(cnt, '0' + mx));
        }

        return ans;
    }
};