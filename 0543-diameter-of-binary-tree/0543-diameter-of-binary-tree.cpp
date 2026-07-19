class Solution {
public:
    int f(TreeNode* node, int& dia) {
        if(node == NULL)
            return 0;

        int left = f(node->left, dia);
        int right = f(node->right, dia);

        dia = max(dia, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        f(root, dia);
        return dia;
    }
};