class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxPerimeter = 0;
        for(int i = 0;i < n-2; i++) {
            if(nums[i] + nums[i+1] > nums[i+2]) {
                maxPerimeter = nums[i] + nums[i+1] + nums[i+2];
            }   
        }
        return maxPerimeter;
    }
};