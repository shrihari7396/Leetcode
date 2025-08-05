class Solution {

    int findInd(vector<int>& nums, int num, vector<bool>& isTheir) {
        int ans = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(isTheir[i] && nums[i] >= num) {
                ans = i;
                isTheir[i] = false;
                break;
            }
        }
        return ans;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        int n = fruits.size();
        vector<bool> isTheir(n, true);
        
        for(auto& num : fruits) {
            findInd(baskets, num, isTheir);
        }

        for(auto it : isTheir) {
            if(it) {
                cnt++;
            }
        }
        return cnt;
    }
};