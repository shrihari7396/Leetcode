class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int> pq;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            pq.push(nums[i]);
            if(s[i] == '1') {
                if(!pq.empty()) {
                    ans += pq.top();
                    pq.pop();
                }
            }
        }
        return ans;
    }
};