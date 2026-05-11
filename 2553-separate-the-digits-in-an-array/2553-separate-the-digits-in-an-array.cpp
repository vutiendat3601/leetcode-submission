class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto& num : nums) {
            string num_str = to_string(num);
            for (auto& c : num_str)
                ans.push_back(c - '0');
        }
        return ans;
    }
};