class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n-2; i++) {
            int j = i+1, k = n-1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;

                if(sum > target) {
                    k--;
                } else {
                    j++;
                }

                int diff = target - sum;
                if(abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                }

            }
        }
        return ans;
    }
};