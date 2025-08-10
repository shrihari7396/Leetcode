#include <unordered_set>
#include <cmath>

class Solution {
private:
    int squareDigits(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;  // better than pow for int
            num /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = squareDigits(n);
        }
        
        return n == 1;
    }
};
