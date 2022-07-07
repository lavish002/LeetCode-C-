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
    
    long minimum(TreeNode* root){
        if(root==NULL)
            return LONG_MAX;
        return min((long)root->val,min(minimum(root->left),minimum(root->right)));
    }

    long maximum(TreeNode* root){
        if(root==NULL)
            return LONG_MIN;
        return max((long)root->val,max(maximum(root->left),maximum(root->right)));
    }

     bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        long min = minimum(root->right);
        long max = maximum(root->left);

        bool output = ((long)root->val>max && (long)root->val<min && isValidBST(root->left) && isValidBST(root->right));
        return output;
    }
};