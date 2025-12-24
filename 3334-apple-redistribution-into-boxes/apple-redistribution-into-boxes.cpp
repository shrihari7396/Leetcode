class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        long long sum = accumulate(apple.begin(), apple.end(), 0);
        int n = capacity.size();
        int ans = 0;
        for(int i = n-1; i >= 0 && sum > 0; i--) {
            sum -= capacity[i];
            ans++;
        }
        return ans;
    }
};