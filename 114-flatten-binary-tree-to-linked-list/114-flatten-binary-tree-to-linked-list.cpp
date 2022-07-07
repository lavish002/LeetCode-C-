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
    TreeNode * check(TreeNode * root){
        if(root==NULL){
            return NULL;
        }
        
        TreeNode* node1 = check(root->left);
        TreeNode* node2 = check(root->right);
        
        
        TreeNode* temp = node1;
        
        if(temp!=NULL){
            while(temp->right!=NULL){
                temp = temp->right;
            }
            temp->right = node2;
            root->right = node1;
            root->left = NULL;
        }
        return root;
    }
    
    void flatten(TreeNode* root) {
        check(root);
    }
};