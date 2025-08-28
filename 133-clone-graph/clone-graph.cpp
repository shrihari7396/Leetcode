/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:   
    void helper(Node* node, unordered_map<int, Node*>& m, Node* newNode) {
        // if(!node) return  node;

        for(int i = 0; i < node->neighbors.size(); i++) {
            int val = node->neighbors[i]->val;
            if(m.find(val) != m.end()) {
                newNode -> neighbors.emplace_back(m[val]);
            } else {
                Node* createdNode = new Node(val);
                m[val] = createdNode;
                newNode -> neighbors.emplace_back(createdNode);
                helper(node->neighbors[i], m, createdNode);
            }
        }
        return;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* newNode = new Node(node -> val);
        unordered_map<int, Node*> m;
        m[node -> val] = newNode;
        helper(node, m, newNode);
        return newNode;
    }
};