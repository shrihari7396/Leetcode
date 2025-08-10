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
    TreeNode* build(int postStart, int postEnd, vector<int>& postorder,
                    int inStart, int inEnd, vector<int>& inorder,
                    unordered_map<int, int>& hash) {
        if (postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int rootIndex = hash[root->val];
        int leftSize = rootIndex - inStart;

        root->left = build(postStart, postStart + leftSize - 1,
                           postorder, inStart, rootIndex - 1, inorder, hash);

        root->right = build(postStart + leftSize, postEnd - 1,
                            postorder, rootIndex + 1, inEnd, inorder, hash);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        return build(0, postorder.size() - 1,
                     postorder, 0, inorder.size() - 1, inorder, m);
    }
};
