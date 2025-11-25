class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ans = 0;
        for(int i = 1; i <= k; i++) {
            ans = (ans*10+1) % k;
            if(ans == 0) return i;
        }
        return -1;
    }
};