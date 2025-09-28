class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // ✅ minimum is in the right half
                low = mid + 1;
            } else {
                // ✅ minimum is in the left half (including mid)
                high = mid;
            }
        }

        // when loop ends, low == high
        return nums[low];
    }
};
