class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = INT_MAX;
        long long maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
            }
            if(nums[i] < mini) {
                mini = nums[i];
            }
        }
        return k*(maxi - mini);
    }
};