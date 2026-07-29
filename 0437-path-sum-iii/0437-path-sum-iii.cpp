class Solution {
public:
    unordered_map<long long, int> mpp;

    int dfs(TreeNode* root, long long sum, int target) {
        if(root == NULL) return 0;

        sum += root->val;
        int cnt = mpp[sum - target];
        mpp[sum]++;

        cnt += dfs(root->left, sum, target);
        cnt += dfs(root->right, sum, target);

        mpp[sum]--;
        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mpp[0] = 1;
        return dfs(root, 0LL, targetSum);
    }
};