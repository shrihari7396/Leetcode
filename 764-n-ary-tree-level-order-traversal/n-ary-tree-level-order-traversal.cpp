/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void fillQueue(vector<Node*>& nea, queue<Node*>& q) {
        for(int i =  0; i < nea.size(); i++) {
            q.push(nea[i]);
        }
        return;
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};

        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++) {
                Node* par = q.front(); q.pop();
                fillQueue(par->children, q);
                temp.emplace_back(par -> val);
            }
            ans.emplace_back(temp);
        }

        return ans;
    }
};