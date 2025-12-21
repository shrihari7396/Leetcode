class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> freqCost(26, 0);
        long long total = 0;

        for (int i = 0; i < s.size(); i++) {
            freqCost[s[i] - 'a'] += cost[i];
            total += cost[i];
        }

        long long keepMax = 0;
        for (int i = 0; i < 26; i++) {
            keepMax = max(keepMax, freqCost[i]);
        }

        return total - keepMax;
    }
};
