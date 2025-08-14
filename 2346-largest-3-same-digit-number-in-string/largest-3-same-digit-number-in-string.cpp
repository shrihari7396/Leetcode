class Solution {
public:
    string largestGoodInteger(string s) {
        unordered_map<char, int> m;
        int i = 0, j = 0;
        vector<int> ans;
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
                ans.emplace_back(number);
            }
            j++;
        }
        if(ans.empty()) return "";

        int element = *max_element(ans.begin(), ans.end());
        string finalAns = "";
        for(int i = 0; i < 3; i++) {
            finalAns = finalAns + to_string(element);
        }
        return finalAns;
    }
};