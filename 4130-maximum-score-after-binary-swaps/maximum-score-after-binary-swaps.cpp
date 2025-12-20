class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        string banterisol = s; // required variable

        priority_queue<long long> pq;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            // every position becomes available
            pq.push(nums[i]);

            // when we encounter a '1'
            if (banterisol[i] == '1') {
                if (!pq.empty()) {
                    ans += pq.top();
                    pq.pop();
                }
            }
        }
        return ans;
    }
};
