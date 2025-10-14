class Solution {
private:
    int helper(int i, int amount, vector<int>& coins, map<pair<int, int>, int>& m) {
        if(amount < 0) return 0;
        if(i < 0) return 0;
        if(i == 0 && amount == 0) return 1;
        if(m.find({i, amount}) != m.end()) {
            return m[{i, amount}];
        }
        int take = helper(i, amount-coins[i], coins, m);
        int notTake = helper(i-1, amount, coins, m);
        return m[{i, amount}] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        map<pair<int, int>, int> m;
        return helper(n-1, amount, coins, m);
    }
};