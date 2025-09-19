class Solution {
private:
    long long calculateHrs(vector<int>& piles, int k) {
        long long hrs = 0;
        for(int it : piles) {
            hrs += ceil((it*1.00)/k);
        }
        return hrs;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long calculatedHrs = calculateHrs(piles, mid);

            if(calculatedHrs <= h) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};