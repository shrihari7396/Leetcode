class Solution {
public:
    string largestGoodInteger(string s) {
        int best = -1;
        for (int i = 0; i <= (int)s.size() - 3; i++) {
            if (s[i] == s[i+1] && s[i] == s[i+2]) {
                int digit = s[i] - '0';
                best = max(best, digit);
            }
        }
        if (best == -1) return "";
        return string(3, '0' + best);
    }
};
