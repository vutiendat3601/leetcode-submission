class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) { return a[0] < b[0]; });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>&temp = ans[ans.size() - 1], &interval = intervals[i];

            if (interval[0] <= temp[0] && temp[1] <= interval[1]) {
                // inside
                temp[0] = interval[0], temp[1] = interval[1];
            } else if (temp[0] <= interval[0] && interval[1] <= temp[1]) {
                // include
                // do nothing
            } else if (temp[1] < interval[0]) {
                // smaller
                ans.push_back(interval);
            } else if (interval[1] < temp[0]) {
                // bigger, because it's sorted, so this case can't happen
                // do nothing
            } else {
                temp[0] = min(temp[0], interval[0]),
                temp[1] = max(temp[1], interval[1]);
            }
        }
        return ans;
    }
};