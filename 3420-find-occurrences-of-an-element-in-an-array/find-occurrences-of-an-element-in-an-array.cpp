class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> hash, ans;
        for(int i = 0; i < n; i++) {
            if(x == nums[i]) {
                hash.emplace_back(i);
            }
        }

        for(auto &it : queries) {
            if(it > hash.size()) {
                ans.emplace_back(-1);
            } else {
                ans.emplace_back(hash[it-1]);
            }
        }

        for(int i = 0; i < hash.size(); i++) {
            cout << hash[i] << " ";
        }
        return ans;
    }
};