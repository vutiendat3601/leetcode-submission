class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int i = 0;
        while (i < (1 << n)) {
            ans.push_back(i ^ (i >> 1));
            i++;
        }
        return ans;
    }
};