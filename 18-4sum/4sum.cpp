class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ansTemp;

        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                unordered_set<long long> hash;
                for(int k = j + 1; k < n; k++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long required = (long long)target - sum;

                    if(hash.find(required) != hash.end()) {
                        vector<int> tmp = {nums[i], nums[j], nums[k], (int)required};
                        sort(tmp.begin(), tmp.end());
                        ansTemp.insert(tmp);
                    }

                    hash.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(ansTemp.begin(), ansTemp.end());
    }
};
