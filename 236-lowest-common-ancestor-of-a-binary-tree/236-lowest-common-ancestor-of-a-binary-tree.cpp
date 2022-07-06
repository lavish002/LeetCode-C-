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
    bool find(TreeNode* root, TreeNode* p, TreeNode* q){
        bool ans = false;
        if(root==NULL) return false;
        
        if(root==p || root==q)
            return true;
        
        if (find(root->right, p,q)||find(root->left,p,q))
            return true;
        
        return ans;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        
        while(root!=NULL){
            ans = root;
            if(root != p && root != q){
                bool f1 = find(root->right,p,q);
                bool f2 = find(root->left,p,q);

                if(f1== true && f2==false){
                    ans = root->right;
                    root=root->right;
                }
                if(f2== true && f1==false){
                    ans = root->left;
                    root=root->left;
                }
                if(f2 == true && f1==true){
                    break;
                }
            }else 
                break;
        }
        return ans;
    }
};