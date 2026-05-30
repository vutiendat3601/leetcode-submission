class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 1, i = n - 1;
        while (carry && i >= 0) {
            int addition = digits[i] + carry;
            digits[i] = addition % 10;
            carry = addition >= 10 ? 1 : 0;
            i--;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};