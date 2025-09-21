class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, int> m;
        for(int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }
        vector<pair<int, int>> list;
        for(auto& it : friends) {
            int pos = m[it];
            list.push_back({pos, it});
        }
        sort(list.begin(), list.end());
        vector<int> ans;
        for(auto& it : list) {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};