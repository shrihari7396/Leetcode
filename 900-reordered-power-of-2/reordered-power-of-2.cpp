class Solution {
private:
    string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }

public:
    bool reorderedPowerOf2(int n) {
        string sortedN = sortDigits(n);
        for (int i = 0; i < 31; i++) { // 2^0 to 2^30 fits in int
            if (sortedN == sortDigits(1 << i)) return true;
        }
        return false;
    }
};
