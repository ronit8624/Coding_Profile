class Solution {
public:
    int dfs(TreeNode* node) {
        if(node == NULL) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if(node->left == NULL) return 1 + right;
        if(node->right == NULL) return 1 + left;

        return 1 + min(left, right);
    }

    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};