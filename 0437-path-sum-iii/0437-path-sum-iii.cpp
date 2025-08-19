/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, long long sum) {
        if (!root) {
            return 0;
        }
        int count = 0;
        if (root->val == sum) {
            count = 1;
        }
        long long newsum = sum - root->val;
        count += solve(root->left, newsum);
        count += solve(root->right, newsum);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        return pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum) + solve(root, targetSum);
    }
};