class Solution {
public:
    int smallestNumber(int n) {
        string s = "";
        int tmp = n;
        while(tmp > 0) {
            s += tmp % 2 ? "1" : "0";
            tmp /= 2;
        }
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') cnt++;
        }
        if(cnt == s.size()) return n;
        reverse(s.begin(), s.end());
        int ind = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') ind++;
            else break;
        }
        for(int i = ind; i < s.size(); i++) {
            s[i] = '1';
        }
        int ans = 0;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                ans += pow(2, i);
            } else {
                break;
            }
        }
        return ans;
    }
};