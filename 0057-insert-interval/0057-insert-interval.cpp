class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        ans.push_back(newInterval);
        for (vector<int>& interval : intervals) {
            vector<int>& temp = ans[ans.size() - 1];
            if (interval[0] <= temp[0] && temp[1] <= interval[1]) {
                temp[0] = interval[0], temp[1] = interval[1];
            } else if (temp[0] <= interval[0] && interval[1] <= temp[1]) {
                // do nothing
            } else if (interval[1] < temp[0]) {
                vector<int> res(temp);
                temp[0] = interval[0], temp[1] = interval[1],
                ans.push_back(res);
            } else if (temp[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                temp[0] = min(interval[0], temp[0]),
                temp[1] = max(interval[1], temp[1]);
            }
        }
        return ans;
    }
};