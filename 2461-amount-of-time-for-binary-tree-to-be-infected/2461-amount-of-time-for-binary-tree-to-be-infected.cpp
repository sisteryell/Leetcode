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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*>q;q.push(root);
        TreeNode* target;
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root]=nullptr;
        while(!q.empty()){
            TreeNode* node=q.front();q.pop();
            if(node->val==start){
                target=node;
            }
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
        }
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        q.push(target);
        int ans=-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* node=q.front();q.pop();vis[node]=true;
                if(node->left and !vis[node->left]){
                    q.push(node->left);
                }
                if(node->right and !vis[node->right]){
                    q.push(node->right);
                }
                if(parent[node] and !vis[parent[node]]){
                    q.push(parent[node]);
                }
            }
            ans++;
        }
        return ans;
    }
};