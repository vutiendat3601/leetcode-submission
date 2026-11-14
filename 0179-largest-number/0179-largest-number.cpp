class Solution {
private:
    static bool cmp(int a, int b) {
        string a_str = to_string(a), b_str = to_string(b);
        if (a_str + b_str > b_str + a_str)
            return true;
        return false;
    }

public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        if (!nums[0])
            return "0";
        for (auto& num : nums)
            ans += to_string(num);
        return ans;
    }
};