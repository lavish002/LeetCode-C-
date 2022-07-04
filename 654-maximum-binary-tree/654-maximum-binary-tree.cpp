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
    TreeNode* helper(vector<int> & nums, int n){
        
        if(n==0)
            return NULL;
        
        int imax = 0;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[imax])
                imax=i;
        }
        
        
        TreeNode* temp = new TreeNode;
        temp->val = nums[imax];
        
        if(imax+1<n){
            vector<int> copy;
            for(int i=imax+1; i<n; i++)
                copy.push_back(nums[i]);
            temp->right = helper(copy, (n-imax-1));
        }
        else temp->right = NULL;
        
        if(imax>0){
            vector<int> copy;
            for(int i=0; i<imax; i++)
                copy.push_back(nums[i]);

            temp->left = helper(copy, imax);
        }
        else temp->left = NULL;
        
        return temp;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, n);
    }
};