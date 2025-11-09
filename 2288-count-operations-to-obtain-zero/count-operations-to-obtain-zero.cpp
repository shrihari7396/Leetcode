class Solution {
public:
    int countOperations(int nums1, int nums2) {
        int ans = 0;

        while(nums1 != 0 && nums2 != 0) {
            if(nums1 >= nums2) {
                ans += nums1 / nums2;
                nums1 = nums1 % nums2;
            }else {
                ans += nums2 / nums1;
                nums2 = nums2 % nums1;
            }
        }
        return ans;
    }
};