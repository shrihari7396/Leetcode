class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) st.push(nums[i]);
            else {
                while(!st.empty() && st.top() < abs(nums[i]) && st.top() > 0) st.pop();
                if(!st.empty() && st.top() == abs(nums[i])) st.pop();
                else if(st.empty() || st.top() < 0) st.push(nums[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.emplace_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};