class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int, int> m;
        int maxi = 0;
        int l = 0, r = 0;
        int n = f.size();
        while(r < n) {
            m[f[r]] ++;
            while(m.size() > 2) {
                m[f[l]] --;
                if(m[f[l]] == 0) {
                    m.erase(f[l]);
                }
                l++;
            }
            maxi = max(maxi, (r-l+1));
            r++;
        }
        return maxi;
    }
};