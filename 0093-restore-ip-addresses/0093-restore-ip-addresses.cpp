class Solution {
private:
    vector<string> ans;
    string ans_item = "";
    int cnt = 0, n = 0;
    string s;

    void backtrack(int k) {
        if (k >= n) {   
            if (cnt < 4)
                return;
            ans.push_back(ans_item.substr(0, ans_item.size() - 1));
            return;
        }
        if (cnt >= 4)
            return;

        string tmp = s.substr(k, 1);
        int ans_item_size = ans_item.size(), val = stoi(tmp);
        ans_item += tmp + ".", cnt++, backtrack(k + 1),
            ans_item.resize(ans_item_size), cnt--;

        for (int i = 2; i <= min(n - k, 3); i++) {
            tmp = s.substr(k, i);
            if (!tmp.starts_with("0")) {
                val = stoi(tmp);
                if (val <= 255)
                    ans_item += tmp + ".", cnt++, backtrack(k + i),
                        ans_item.resize(ans_item_size), cnt--;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        n = s.size();
        backtrack(0);
        return ans;
    }
};