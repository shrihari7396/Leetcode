class Solution {
private:
    string helper(pair<char, int>& first, pair<char, int>& second) {
        string res = "";
        for (int i = 0; i < first.second; i++) res += first.first;
        for (int i = 0; i < second.second; i++) res += second.first;
        return res;
    }

public:
    string removeSubstring(string s, int k) {
        int n = s.size();
        if (n == 0) return "";

        stack<pair<char, int>> st;
        st.push({s[0], 1});

        for (int i = 1; i < n; i++) {
            auto it = st.top();
            if (it.first == s[i]) {
                st.pop();
                st.push({it.first, it.second + 1});
            } else {
                st.push({s[i], 1});
            }
        }

        vector<pair<char, int>> arr;
        while (!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(), arr.end());

        bool changed = true;
        while(changed) {
            changed = false;
            vector<pair<char, int>> tmp;
            for(int i = 0; i < arr.size(); i++) {
                if(i + 1 < arr.size() && arr[i].first == '(' && arr[i+1].first == ')') {
                    int rCnt = min(arr[i].second, arr[i+1].second);
                    if(rCnt >= k) {
                        arr[i].second -= k;
                        arr[i+1].second -= k;
                        changed = true;
                    }
                }

                if(arr[i].second > 0) {
                    if(!tmp.empty() && tmp.back().first == arr[i].first) {
                        tmp.back().second += arr[i].second;
                    } else {
                        tmp.emplace_back(arr[i]);
                    }
                }
            }
            arr = tmp;
        }

        string ans = "";
        for (auto& p : arr) ans += string(p.second, p.first);
        return ans;
    }
};
