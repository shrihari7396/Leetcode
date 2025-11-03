#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Pair {
        int first, second;
        Pair(int f, int s) : first(f), second(s) {}
    };

    int process(const Pair& p, const vector<int>& prefixSum, const vector<int>& neededTime) {
        int sum = prefixSum[p.second + 1] - prefixSum[p.first];
        int maxVal = 0;
        for (int i = p.first; i <= p.second; i++) {
            maxVal = max(maxVal, neededTime[i]);
        }
        return sum - maxVal;
    }

public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<Pair> subarrays;

        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && colors[i] == colors[j + 1]) {
                j++;
            }
            if (j > i) { // group found
                subarrays.emplace_back(i, j);
            }
            i = j + 1;
        }

        vector<int> prefixSum(n + 1, 0);
        for (int k = 0; k < n; k++) {
            prefixSum[k + 1] = prefixSum[k] + neededTime[k];
        }

        int ans = 0;
        for (auto& p : subarrays) {
            ans += process(p, prefixSum, neededTime);
        }

        return ans;
    }
};
