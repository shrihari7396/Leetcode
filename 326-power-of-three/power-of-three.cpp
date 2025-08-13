class Solution {
public:
    bool isPowerOfThree(int n) {
        int cntOne = 0, cnt = 0;
        if(n < 3 && n != 1) return false;
        while(n > 0) {
            int mod = n%3;
            if(mod > 1) return false;
            if(mod == 1) {
                if(cnt == 1) return false;
                cnt ++;
            }
            n/=3;
        }
        return true;
    }
};