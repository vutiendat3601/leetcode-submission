class Solution {
private:
    vector<pair<int, string>> ROMAN = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};

public:
    string intToRoman(int num) {
        string ans = "";
        for (auto& [value, symbol] : ROMAN) {
            while (num >= value)
                ans += symbol, num -= value;
        }
        return ans;
    }
};