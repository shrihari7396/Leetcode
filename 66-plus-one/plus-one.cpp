class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] < 9) {
            digits[n-1] += 1;
            return digits;
        }
        reverse(digits.begin(), digits.end());
        int ind = 0;
        digits[ind] += 1;
        int carry = digits[ind] / 10;
        digits[ind] = digits[ind] % 10;
        ind ++;

        while(ind < n && carry != 0) {
            digits[ind] += carry;
            carry = digits[ind] / 10;
            digits[ind] = digits[ind] % 10;
            ind++;
        }
        if(ind == n && carry != 0) {
            digits.emplace_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;

    }
};