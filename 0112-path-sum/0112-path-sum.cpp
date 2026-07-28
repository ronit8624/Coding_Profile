class Solution {
public:
    bool f(TreeNode* root, int sum, int target) {
        if(root == NULL) return false;

        sum += root->val;

        if(root->left == NULL && root->right == NULL) {
            return sum == target;
        }

        return f(root->left, sum, target) ||
               f(root->right, sum, target);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root, 0, targetSum);
    }
};