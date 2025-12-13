class Solution {
private:
    bool first(const string& s) {
        if (s.empty())
            return false;

        for (char it : s) {
            if (!((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z') ||
                  (it >= '0' && it <= '9') ||
                  (it == '_'))) {
                return false;
            }
        }
        return true;
    }

    bool second(string& s, unordered_map<string, int>& m) {
        return m.find(s) != m.end();
    }

public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();

        unordered_map<string, int> priority = {{"electronics", 0},
                                               {"grocery", 1},
                                               {"pharmacy", 2},
                                               {"restaurant", 3}};

        vector<pair<string, string>> valid;
        for (int i = 0; i < n; i++) {
            if (isActive[i] && first(code[i]) && second(businessLine[i], priority)) {

                valid.push_back({businessLine[i], code[i]});
            }
        }

        sort(valid.begin(), valid.end(), [&](auto& a, auto& b) {
            if (priority[a.first] != priority[b.first]) {
                return priority[a.first] < priority[b.first];
            }
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto& p : valid) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
