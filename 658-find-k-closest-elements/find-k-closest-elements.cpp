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
        int n = arr.size();
        for(int i = 0; i < n; i ++) {
            pq.push({abs(arr[i]-x), arr[i]});
            if(!pq.empty() && pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()) {
            auto it = pq.top();pq.pop();
            ans.emplace_back(it.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};