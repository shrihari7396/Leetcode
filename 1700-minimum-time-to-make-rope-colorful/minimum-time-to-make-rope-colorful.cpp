#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    template <typename T, typename V>
    struct Pair {
        T first;
        V second;
        Pair(T f, V s) : first(f), second(s) {}
    };

    int process(Pair<int, int> p, const vector<int>& neededTime) {
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        for (int i = p.first; i <= p.second; i++) {
            pq.push(neededTime[i]);
        }
        int sum = 0;
        while (pq.size() != 1) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }

public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<Pair<int, int>> subarrays;
        int i = 0;
        int j = i + 1;
        int n = colors.size();

        while (i < n && j < n) {
            if (colors[i] == colors[j]) {
                j++;
            } else {
                subarrays.emplace_back(i, j - 1);
                i = j;
                j++;
            }
        }
        if (i != j) {
            subarrays.emplace_back(i, j - 1);
        }

        int ans = 0;
        for (auto& p : subarrays) {
            ans += process(p, neededTime);
        }
        return ans;
    }
};
