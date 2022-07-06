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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=false;
        
        if(p==NULL && q==NULL) return true;
        
        if(p!=NULL && q!=NULL)
            if(p->val == q->val) ans = true;
        
        if(ans == true)
            ans = (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
        
        
        return ans;
    }
};