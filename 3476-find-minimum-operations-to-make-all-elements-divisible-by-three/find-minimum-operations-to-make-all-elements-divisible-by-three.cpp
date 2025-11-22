class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(auto& it : nums) {
            int tmp = it % 3;
            int tmp2 = 3 - tmp;
            ans += min(tmp, tmp2);
        }
        return ans;
    }
};