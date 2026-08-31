// Brute Force

class Solution {
public:
    bool isValid(string s) {
        const string parentheses = "()", curly_brackets = "{}",
                     square_brackets = "[]";
        int pt, cb, sb;
        bool found = 1;
        while (found) {
            found = 0;
            if ((pt = s.find(parentheses)) != string::npos)
                s.erase(pt, 2), found = 1;
            if ((cb = s.find(curly_brackets)) != string::npos)
                s.erase(cb, 2), found = 1;
            if ((sb = s.find(square_brackets)) != string::npos)
                s.erase(sb, 2), found = 1;
        }
        return !s.size();
    }
};