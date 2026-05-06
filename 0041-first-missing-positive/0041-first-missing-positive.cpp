class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        unordered_set<int> unq(nums.begin(), nums.end());
        bool cont = 1;
        while (cont) {
            cont = 0;
            if (unq.count(ans))
                ans++, cont = 1;
        }
        return ans;
    }
};

// Hashing, time: O(n), space: O(n)