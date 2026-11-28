class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = 0;
        vector<pair<int, int>> ps(n);
        for (int i = 0; i < n; i++)
            ps[i] = {position[i], speed[i]};
        sort(ps.begin(), ps.end());
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
            st.push(ps[i]);
        pair<int, int> item, item1;
        while (st.size()) {
            item = st.top(), st.pop();
            double time = (double)(target - item.first) / item.second;
            while (st.size()) {
                item1 = st.top();
                double time1 = (double)(target - item1.first) / item1.second;
                if (time1 <= time)
                    st.pop();
                else
                    break;
            }
            ans++;
        }

        return ans;
    }
};