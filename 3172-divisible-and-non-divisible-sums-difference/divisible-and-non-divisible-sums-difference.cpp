class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for(int i = 0; i <= n; i++) {
            num2 += i%m == 0 ? i : 0;
            num1 += i%m == 0 ? 0 : i;
        }
        return num1 - num2;
    }
};