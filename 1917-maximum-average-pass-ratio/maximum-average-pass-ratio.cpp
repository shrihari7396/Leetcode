class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calculation = [](int passes,int total) {
            return (double)(passes+1)/(double)(total+1) - (double)passes/total;
        };
        priority_queue<pair<double, pair<int, int>>> maxHeap;
    for(const auto& single:classes) {
        maxHeap.push({calculation(single[0], single[1]),{single[0], single[1]}});
    }

    while(extraStudents--) {
        auto temp=maxHeap.top();maxHeap.pop();
        int pass=temp.second.first;
        int total=temp.second.second;
        maxHeap.push({calculation(pass+1, total+1), {pass+1, total+1}});
    }

    double ans=0;
    while(!maxHeap.empty()) {
        auto it=maxHeap.top();maxHeap.pop();
        ans+=(double)it.second.first/it.second.second;
    }

    return ans/classes.size();
    }
};