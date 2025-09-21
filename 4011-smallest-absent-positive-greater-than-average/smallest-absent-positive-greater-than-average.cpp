class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for (int x : nums) sum += x;

        double avg = (sum * 1.0) / nums.size();

        int ans = floor(avg) + 1;
        if (ans <= 0) ans = 1;

        while (true) {
            if (s.find(ans) == s.end()) {
                return ans;
            }
            ans++;
        }

        return -1; // should never happen
    }
};
