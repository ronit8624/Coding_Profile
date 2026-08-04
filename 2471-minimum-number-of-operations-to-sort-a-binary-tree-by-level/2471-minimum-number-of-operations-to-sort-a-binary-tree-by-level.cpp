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
    int getSwaps(vector<int>& original) {
        int n = original.size();
        vector<int> target = original;
        sort(target.begin(), target.end());
        unordered_map<int, int> indMap;
        int swaps = 0;

        for(int i=0;i<n;i++) {
            indMap[original[i]] = i;
        }

        for(int i=0;i<n;i++) {
            if(original[i] != target[i]) {
                swaps++;

                int curPos = indMap[target[i]];
                indMap[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }

        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for(int i=0;i<size;i++) {
                auto node = q.front(); q.pop();
                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans += getSwaps(level);
        }

        return ans;
    }
};