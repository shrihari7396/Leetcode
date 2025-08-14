class Solution {
public:
    string largestGoodInteger(string s) {
        unordered_map<char, int> m;
        int i = 0, j = 0;
        int best = -1;
        while(j < s.size()) {
            m[s[j]] ++;

            if((j - i + 1) > 3) {
                m[s[i]]--;
                if(m[s[i]] <= 0) {
                    m.erase(s[i]);
                }
                i++;
            }

            if(m.size() == 1 && m[s[i]] == 3) {
                int number = s[i] - '0';
                if(number > best) best = number;
            }
            j++;
        }
        if(best == -1) return "";

        return string(3, '0' + best);
    }
};