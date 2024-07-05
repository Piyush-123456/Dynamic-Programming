
class Solution {
public:
    int solve(TreeNode* root) {
        if (!root)
            return 0;
        int robhouse = 0, dontrob = 0;
        robhouse += root->val;
        if (root->left) {
            robhouse += solve(root->left->left) + solve(root->left->right);
        }
        if (root->right) {
            robhouse += solve(root->right->left) + solve(root->right->right);
        }
        dontrob = solve(root->left) + solve(root->right);
        return max(robhouse, dontrob);
    }

    int solveusingMemo(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if (!root) {
            return 0;
        }

        if (dp.find(root) != dp.end()) {
            return dp[root];
        }

        int robhouse = 0, dontrob = 0;
        robhouse += root->val;
        if (root->left) {
            robhouse += solveusingMemo(root->left->left, dp) +
                        solveusingMemo(root->left->right, dp);
        }
        if (root->right) {
            robhouse += solveusingMemo(root->right->left, dp) +
                        solveusingMemo(root->right->right, dp);
        }
        dontrob =
            solveusingMemo(root->left, dp) + solveusingMemo(root->right, dp);
        dp[root] = max(robhouse, dontrob);
        return dp[root];
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solveusingMemo(root, dp);
    }
};
