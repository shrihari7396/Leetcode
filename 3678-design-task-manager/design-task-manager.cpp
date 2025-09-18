#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    unordered_map<int, pair<int, int>> m;
    priority_queue<tuple<int, int, int>> pq; 
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& it : tasks) {
            m[it[1]] =  {it[0], it[2]};
            pq.push({it[2], it[1], it[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        m[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto& it = m[taskId];
        it.second = newPriority;
        pq.push({it.second, taskId, it.first});
    }
    
    void rmv(int taskId) {
        m.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int priority = get<0>(it);
            int taskId = get<1>(it);
            int userId = get<2>(it);

            if(m.find(taskId) == m.end() || m[taskId].second != priority) {
                continue;
            }
            m.erase(taskId);
            return userId;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */