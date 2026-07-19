class Solution {
public:
    int f(TreeNode* node) {
        if(node == NULL)
            return 0;

        int left = f(node->left);
        if(left == -1) return -1;

        int right = f(node->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return f(root) != -1;
    }
};