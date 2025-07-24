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
    // void markParent(TreeNode* root, map<TreeNode*, TreeNode*>& parent){
    //     if(root == NULL) return;

    //     if(root -> left){
    //         parent[root -> left] = root;
    //     }
    //     if(root -> right){
    //         parent[root -> right] = root;
    //     }

    //     markParent(root -> left, parent);
    //     markParent(root -> right, parent);
    // }
    TreeNode* solve(TreeNode* root, int key){

        if(root == NULL) return root;

        if(key == root -> val){

            if(root -> left == NULL && root -> right == NULL){
                return NULL;
            }
            else if(root -> left == NULL && root -> right != NULL){
                return root -> right;
            }
            else if(root -> left != NULL && root -> right == NULL){
                return root -> left;
            }
            else{
                TreeNode* pred = root -> left;
                while(pred -> right){
                    pred = pred -> right;
                }
                root -> val = pred -> val;

                root -> left = solve(root -> left, pred -> val);

            }
        }
        if(key >  root -> val){
            root -> right = solve(root -> right, key);
        }
        else{
            root -> left = solve(root -> left, key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // map<TreeNode*, TreeNode*> parent;
        // markParent(root, parent);
        return solve(root, key);
    }
};