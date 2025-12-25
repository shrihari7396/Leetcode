class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long ans = 0;
        int dec = 0;
        int j = happiness.size() - 1;

        while (j >= 0 && k > 0) {
            int val = happiness[j] - dec;
            if (val <= 0) break;
            ans += val;
            dec++;
            j--;
            k--;
        }
        return ans;
    }
};
