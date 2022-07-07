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
    TreeNode* printTree(TreeNode* root){
        TreeNode * ans;
        if(root==NULL) return NULL;
        ans = root;
        ans->left = printTree(root->left);
        ans->right = printTree(root->right);
        return ans;
    }
    
    TreeNode* searchBST(TreeNode* root, int k) {
        TreeNode* ans=NULL;
    
        if(root == NULL)
            return ans;

        if(root->val == k){
            ans = printTree(root);
            return ans;
        }

        if(k < root->val)
            ans = searchBST(root->left, k);
        else if(k >root->val)
            ans = searchBST(root->right, k);

        return ans;
        }
};