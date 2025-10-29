class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        int i = 0, j = nums.size() - 1;
        long long sum = 0;
        while (i <= j) {
            sum += 1LL * nums[j] * nums[j];
            j--;
            if (i <= j) {
                sum -= 1LL * nums[i] * nums[i];
                i++;
            }
        }
        return sum;
    }
};
