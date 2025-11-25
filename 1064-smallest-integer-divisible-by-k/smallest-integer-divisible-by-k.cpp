class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // impossible cases
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int check = 1 % k;   // remainder of current repunit
        int length = 1;      // current length

        while (check != 0) {
            check = (check * 10 + 1) % k;   // append '1'
            length++;
        }

        return length;
    }
};
