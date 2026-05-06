class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0, sign = 1;
        long ans = 0;

        while (i < n) {
            char c = s[i];
            if (isdigit(c)) {
                break;
            } else if ((c == '-' || c == '+') &&
                       (i + 1 < n && isdigit(s[i + 1]))) {
                sign = c == '-' ? -1 : 1;
                i++;
                break;
            } else if (c != ' ') {
                return 0;
            }
            i++;
        }

        while (i < n) {
            char c = s[i];
            if (!isdigit(c)) {
                break;
            } else {
                ans *= 10, ans += c - '0';
                long cur_ans = ans * sign;
                if (cur_ans <= INT_MIN)
                    return INT_MIN;
                if (cur_ans >= INT_MAX)
                    return INT_MAX;
            }
            i++;
        }
        ans *= sign;
        return (int)ans;
    }
};