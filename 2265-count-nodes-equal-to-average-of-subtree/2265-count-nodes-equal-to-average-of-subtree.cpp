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
    pair<int,int> dfs(TreeNode* root, int &ans) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto [leftsum, leftcount] = dfs(root->left, ans);
        auto [rightsum, rightcount] = dfs(root->right, ans);

        int totalsum = leftsum + rightsum + root->val;
        int totalcount = leftcount + rightcount + 1;
        if (totalsum / totalcount == root->val) {
            ans++;
        }
        return {totalsum, totalcount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        pair<int, int> total = dfs(root, ans);
        return ans;
    }
};