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

class Data {
    public:
    int mx;
    int mn;
    bool isBST;
    int sum;
};
class Solution {
public:
    Data solve(TreeNode* root, int &maxsum){
        if(!root) return {INT_MIN,INT_MAX,true,0};
        
        Data left=solve(root->left,maxsum);
        Data right=solve(root->right,maxsum);
        
        Data currData;
        
        currData.sum=left.sum + right.sum +root->val;
        currData.mx=max(root->val,right.mx);
        currData.mn=min(root->val,left.mn);
        
        if(left.isBST && right.isBST &&(root->val>left.mx && root->val<right.mn)){
            currData.isBST=true;
        }
        else{
            currData.isBST=false;
        }
        if(currData.isBST){
            maxsum=max(maxsum,currData.sum);
        }  
        return currData;
    }
    int maxSumBST(TreeNode* root) {
        int maxsum = 0;
        Data temp = solve(root,maxsum);
        
        return maxsum;
    }
};