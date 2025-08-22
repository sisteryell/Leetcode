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
    int ans=0;
    vector<int> solve(TreeNode* root){
        if(!root)return {0,0};
        vector<int>reL=solve(root->left);
        vector<int>reR=solve(root->right);
        int L=reL[0];
        int R=reR[1];
        ans=max({ans,L,R});
        return{R+1,L+1};
    }
    int longestZigZag(TreeNode* root) {
        solve(root);
        return ans;
    }
};