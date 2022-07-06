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
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        int ans1 = diameterOfBinaryTree(root->left);
        int ans2 = diameterOfBinaryTree(root->right);
        ans = max(ans1,ans2);
        int h1 = maxDepth(root->left);
        int h2 = maxDepth(root->right);
        int temp = h1+h2;
        if(temp > ans)
            ans=temp;
        return ans;
    }
};