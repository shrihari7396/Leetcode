class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1, n = nums.size();
        int i = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1 && prev == -1) {
                prev = i;
            } else if(nums[i] == 1) {
                int dist = i - prev - 1;
                if(dist < k) return false;
                prev = i;
            }
        }
        return true;
    }
};