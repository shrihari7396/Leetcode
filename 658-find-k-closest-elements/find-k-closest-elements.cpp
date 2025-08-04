class Solution {
private:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            // Max heap based on difference, and if tie, max value comes first
            if (a.first == b.first)
                return a.second < b.second; // larger value has higher priority
            return a.first < b.first; // smaller difference has lower priority
        }
    };

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        
        for (int num : arr) {
            pq.push({abs(num - x), num});
            if (pq.size() > k) pq.pop();  // remove farthest
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());  // final result should be sorted
        return ans;
    }
};
