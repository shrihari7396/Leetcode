class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        hash[0] = 1;
        int prefix = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            prefix += nums[i];
            int find = prefix - k;
            if(hash.find(find) != hash.end()) {
                ans += hash[find];
            }
            hash[prefix]++;
        }
        return ans;
    }
};