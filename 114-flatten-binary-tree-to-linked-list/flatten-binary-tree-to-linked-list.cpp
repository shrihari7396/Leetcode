class Solution {
private:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

public:
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<int> pre;
        preorder(root, pre);
        TreeNode* curr = root;
        for (int i = 1; i < pre.size(); i++) {
            curr->left = nullptr;
            curr->right = new TreeNode(pre[i]);
            curr = curr->right;
        }
    }
};
