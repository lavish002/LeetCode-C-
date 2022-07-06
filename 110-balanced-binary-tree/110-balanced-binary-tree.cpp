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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->right), maxDepth(root->left))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool op1=false, op2=false, op3=false;
        if(abs(maxDepth(root->left)-maxDepth(root->right))<=1){
            op1=true;
        }
        op2=isBalanced(root->left);
        op3=isBalanced(root->right);
        
        if(op1==true && op2==true && op3==true)
            return true;
        else 
            return false;
    }
};