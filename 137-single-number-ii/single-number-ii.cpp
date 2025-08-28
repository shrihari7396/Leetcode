class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        sort(nums.begin(), nums.end());
        for(auto& it : nums) {
            m[it]++;
            if(m[it] == 3) m.erase(it);
        }

        for(auto& it:m) {
            if(it.second == 1) {
                return it.first;
            }
        }
        return -1;
    }
};