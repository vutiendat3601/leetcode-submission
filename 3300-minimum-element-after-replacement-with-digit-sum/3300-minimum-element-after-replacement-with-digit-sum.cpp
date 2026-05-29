class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (auto& num : nums) {
            string num_str = to_string(num);
            int sum = 0;
            for (auto& d : num_str)
                sum += d - '0';
            ans = min(ans, sum);
        }
        return ans;
    }
};