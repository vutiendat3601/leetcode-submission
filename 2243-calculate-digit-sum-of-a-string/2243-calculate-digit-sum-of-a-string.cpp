class Solution {
public:
    string digitSum(string s, int k) {
        string ans = s;

        while (s.size() > k) {
            ans = "";
            int i = 0;
            while (i < s.size()) {
                string gr = s.substr(i, k);
                int sum = 0;
                for (auto& c : gr)
                    sum += c - '0';
                ans += to_string(sum);
                i += k;
            }
            s = ans;
        }

        return ans;
    }
};