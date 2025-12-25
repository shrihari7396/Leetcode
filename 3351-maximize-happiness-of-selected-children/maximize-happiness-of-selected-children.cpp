class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long ans = 0;
        int dec = 0;
        int j = happiness.size() - 1;

        while (j >= 0 && k > 0) {
            ans += max(0, happiness[j] - dec);
            dec++;
            k--;
            j--;
        }
        return ans;
    }
};
