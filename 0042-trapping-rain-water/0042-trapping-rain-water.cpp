class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        vector<int> l(n), r(n);
        l[0] = h[0], r[n - 1] = h[n - 1];
        for (int i = 1; i < n; i++) {
            l[i] = max(l[i - 1], h[i]);
            r[n - 1 - i] = max(r[n - i], h[n - 1 - i]);
        }
        for (int i = 1; i < n - 1; i++) {
            ans += min(l[i], r[i]) - h[i];
        }
        return ans;
    }
};

// 2-pointers, time: O(n), space: O(n)