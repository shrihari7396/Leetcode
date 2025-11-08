/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        ans.emplace_back(root -> val);
        preorder(root -> left, ans);
        preorder(root -> right, ans);
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<int> pre;
        preorder(root, pre);
        TreeNode* curr = root;
        root -> left = nullptr;
        for(int i = 1; i < pre.size(); i++) {
            TreeNode* temp = new TreeNode(pre[i]);
            curr -> right = temp;
            curr = curr -> right;
        }
    }
};