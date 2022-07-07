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

    bool check(TreeNode* rRight, TreeNode* rLeft){
        if(rRight==NULL && rLeft==NULL){
            return true;
        }
        else if(rRight==NULL || rLeft==NULL){
            return false;
        }
            
        return rRight->val == rLeft->val && (check(rRight->right, rLeft->left) && check(rRight->left, rLeft->right));
    }
    
    bool isSymmetric(TreeNode* root) {
        return check(root->right, root->left);
    }
};