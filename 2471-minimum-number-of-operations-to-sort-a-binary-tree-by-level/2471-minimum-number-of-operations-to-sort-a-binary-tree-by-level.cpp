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
    int getSwaps(vector<int>& original) {
        vector<int> target = original;
        sort(target.begin(), target.end());
        int n = original.size();
        int swaps = 0;

        unordered_map<int, int> pos;
        for(int ind = 0; ind < n; ind ++) {
            pos[original[ind]] = ind;
        }

        for(int ind = 0; ind < n; ind ++) {
            if(original[ind] != target[ind]) {
                swaps++;

                int curPos = pos[target[ind]];
                pos[original[ind]] = curPos;
                swap(original[curPos], original[ind]);
            }
        }

        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for(int ind = 0; ind < size; ind ++) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans += getSwaps(level);
        }

        return ans;
    }
};