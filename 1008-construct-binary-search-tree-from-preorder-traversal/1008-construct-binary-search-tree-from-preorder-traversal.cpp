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
    
    TreeNode* helper(vector<int>& preorder, int s, int e) {
        if(s>e) return NULL;
        int s1=s+1, e2=e;
        int e1=e2;
        int s2=INT_MAX;
        TreeNode* result = new TreeNode(preorder[s]);
        
        for(int i=s1; i<=e2; i++)
            if(preorder[i]>preorder[s]){
                s2=i;
                e1=s2-1;
                break;
            }
        
        result->left = helper(preorder, s1, e1);
        
        result->right = helper(preorder, s2, e2);
        return result;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};