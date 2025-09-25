class Solution {
public:
    int minBitFlips(int start, int goal) {
        int tmp = start ^ goal; int ans = 0;
        while(tmp != 0) {
            if(tmp & 1) ans++;
            tmp = tmp >> 1;
        }
        return ans;
    }
};