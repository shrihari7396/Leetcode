#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Compare {
        bool operator()(const pair<string, int>& a,
                        const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };

public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {
        queue<int> q;
        q.push(id);
        vector<int> friendsl;
        vector<bool> vis(friends.size(), false);
        vis[id] = true;
        while (!q.empty()) {
            int size = q.size();
            level--;
            for (int i = 0; i < size; i++) {
                int currFriend = q.front();
                q.pop();

                for (int j = 0; j < friends[currFriend].size(); j++) {
                    if (!vis[friends[currFriend][j]]) {
                        q.push(friends[currFriend][j]);
                        vis[friends[currFriend][j]] = true;
                        if (level == 0) {
                            friendsl.emplace_back(friends[currFriend][j]);
                        }
                    }
                }
            }
            if (level == 0) {
                break;
            }
        }
        unordered_map<string, int> m;
        for (auto& f : friendsl) {
            for (auto& video : watchedVideos[f]) {
                m[video]++;
            }
        }

        vector<pair<string, int>> temp;
        for (auto& it : m) {
            temp.push_back({it.first, it.second});
        }

        sort(temp.begin(), temp.end(), Compare());

        vector<string> ans;
        for (auto& it : temp) {
            ans.emplace_back(it.first);
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    
}