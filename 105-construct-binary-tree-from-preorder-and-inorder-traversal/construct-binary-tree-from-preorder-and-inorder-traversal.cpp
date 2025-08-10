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
    TreeNode* build(int preStart, int preEnd, vector<int>& preorder, int inStart, int inEnd, vector<int>& inorder, unordered_map<int, int>& hash)  {
        if(preEnd < preStart || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = hash[root -> val];
        int leftSize = rootIndex - inStart;
        root -> left = build(preStart+1, preStart + leftSize, preorder, inStart, rootIndex - 1, inorder, hash);
        root -> right = build(preStart + leftSize + 1, preEnd, preorder, rootIndex + 1, inEnd, inorder, hash);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int> m;
        for(int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        return build(0, preorder.size()-1, preorder, 0, inorder.size()-1, inorder, m);
    }
};