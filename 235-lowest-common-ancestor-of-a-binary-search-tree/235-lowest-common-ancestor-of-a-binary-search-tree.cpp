/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* val1, TreeNode* val2) {
        
        while( root!=val1 && root!=val2 ){
            if( (val1->val <root->val && val2->val>root->val) || (val1->val>root->val && val2->val<root->val) ){
                break;
            }

            if(val1->val<root->val && val2->val<root->val){
                root = root->left;
            }
            else if(val1->val>root->val && val2->val>root->val){
                root=root->right;
            }
        }
        return root;
    }
};