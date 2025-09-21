class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
    unordered_set<int> friendSet(friends.begin(), friends.end());
    vector<int> ans;
    for (auto& x : order) {
        if (friendSet.count(x)) {
            ans.push_back(x);
        }
    }
    return ans;
}

};