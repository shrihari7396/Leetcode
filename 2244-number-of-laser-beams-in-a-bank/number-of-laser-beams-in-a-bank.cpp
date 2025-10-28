class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> hash;
        int n = bank.size();
        for(int i = 0; i < n; i++) {
            int tmp = bank[i].size();
            int cnt = 0;
            for(int j = 0; j < tmp; j++) {
                if(bank[i][j] == '1') cnt++;
            }
            if(cnt != 0) hash.emplace_back(cnt);
        }
        int ans = 0;
        if(hash.size() == 0) return 0;
        for(int i = 0; i < hash.size()-1; i++) {
            ans += hash[i]*hash[i+1];
        }

        return ans;
    }
};