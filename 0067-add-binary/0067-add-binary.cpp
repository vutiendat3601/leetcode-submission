class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i1 = a.size() - 1, i2 = b.size() - 1, a1, a2, carry = 0, s = 0;
        while (i1 >= 0 && i2 >= 0) {
            a1 = a[i1] - '0', a2 = b[i2] - '0';
            ans += to_string(a1 ^ a2 ^ carry);
            carry = (carry & (a1 | a2)) | (a1 & a2);
            i1--, i2--;
        }

        while (i1 >= 0) {
            a1 = a[i1] - '0';
            ans += to_string(a1 ^ carry);
            carry = a1 & carry;
            i1--;
        }
        while (i2 >= 0) {
            a2 = b[i2] - '0';
            ans += to_string(a2 ^ carry);
            carry = a2 & carry;
            i2--;
        }
        if (carry)
            ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};