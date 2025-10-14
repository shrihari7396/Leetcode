class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int start = 0; start + 2 * k <= n; start++) {
            bool firstInc = true, secondInc = true;

            // check first subarray [start .. start + k - 1]
            for (int i = start + 1; i < start + k; i++) {
                if (nums[i] <= nums[i - 1]) {
                    firstInc = false;
                    break;
                }
            }

            // skip if first isn't increasing
            if (!firstInc) continue;

            // check second subarray [start + k .. start + 2*k - 1]
            for (int i = start + k + 1; i < start + 2 * k; i++) {
                if (nums[i] <= nums[i - 1]) {
                    secondInc = false;
                    break;
                }
            }

            if (firstInc && secondInc) return true;
        }

        return false;
    }
};
