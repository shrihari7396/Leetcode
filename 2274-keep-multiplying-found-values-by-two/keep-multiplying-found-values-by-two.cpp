class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(auto& it : nums) {
            if(it == original) {
                original *= 2;
            }
        }
        return original;
    }
};