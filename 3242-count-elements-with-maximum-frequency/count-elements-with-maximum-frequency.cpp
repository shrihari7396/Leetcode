class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto& it : nums) {
            m[it]++;
        }
        int maxi = 0;
        int  num = 0;
        for(auto it : m) {
            maxi = max(maxi, it.second);
        }
        int ans = 0;
        for(auto& it : m) {
            if(maxi == it.second) {
                ans += it.second;
            }
        }
        return ans;
    }
};