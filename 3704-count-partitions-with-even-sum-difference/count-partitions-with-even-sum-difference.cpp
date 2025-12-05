class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, nums[0]);
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        int ans = 0;
        for(int i = 1; i < n; i++) {
            int left =  prefix[i];
            int right = prefix[n-1] - prefix[i];
            int diff = abs(left - right);
            if(diff%2==0) ans++;
        }
        return ans;
    }
};