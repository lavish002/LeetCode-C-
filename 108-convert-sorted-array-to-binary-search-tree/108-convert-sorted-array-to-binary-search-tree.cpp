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
    TreeNode* sortedBST(vector<int>& nums, int s, int e) {
        if(s>e) return NULL;
        int n = s+(e-s+1)/2;
        TreeNode* root = new TreeNode(nums[n]);
        
        root->left = sortedBST(nums, s, n-1);
        root->right = sortedBST(nums, n+1, e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size()-1;
        return sortedBST(nums, 0, n);
    }
};