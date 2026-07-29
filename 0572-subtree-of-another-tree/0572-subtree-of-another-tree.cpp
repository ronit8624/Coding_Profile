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
public:
    bool isSame(TreeNode* root, TreeNode* sroot) {
        if(root == NULL && sroot == NULL) return true;
        if(root == NULL || sroot == NULL) return false;
        if(root->val != sroot->val) return false;

        return isSame(root->left, sroot->left) &&
                isSame(root->right, sroot->right);
    }
    bool dfs(TreeNode* root, TreeNode* sroot) {
        if(root == NULL) return false;
        if(isSame(root, sroot)) return true;

        return dfs(root->left, sroot) || dfs(root->right, sroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};