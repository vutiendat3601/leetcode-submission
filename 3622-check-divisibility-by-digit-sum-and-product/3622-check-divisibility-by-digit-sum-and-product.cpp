class Solution {
public:
    bool checkDivisibility(int n) {
        int p = 1, s = 0;
        string n_str = to_string(n);
        for (int i = n_str.size() - 1; i >= 0; i--)
            p *= n_str[i] - '0', s += n_str[i] - '0';
        return n % (p + s) == 0;
    }
};