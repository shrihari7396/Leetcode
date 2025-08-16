class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        int highest = x / 2;
        int low = 1;int high = x;
        int mid = 0;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(1LL * mid * mid > x) {
                high = mid - 1;
            } else if(1LL * mid * mid < x) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return high;
    }
};