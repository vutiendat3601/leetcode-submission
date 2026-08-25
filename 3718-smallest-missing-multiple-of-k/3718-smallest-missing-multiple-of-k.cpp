class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int i = 1;
        while (s.count(k * i))
            i++;
        return k * i;
    }
};