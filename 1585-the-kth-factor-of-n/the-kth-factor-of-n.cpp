class Solution {
public:
    int kthFactor(int n, int k) {
        int ans = -1;
        for(int i = 1; i <= n && k != 0; i++) {
            if(n%i == 0) {
                k--;
                ans = i;
            }
        }
        return k == 0 ? ans : -1;
    }
};