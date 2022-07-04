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
     void inorder(TreeNode*& ans, TreeNode* root) {
        if (!root) return;
        inorder(ans, root->left);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        inorder(ans, root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp;
        TreeNode* ans = new TreeNode();
        temp = ans;
        inorder(ans, root);
        return temp->right;
    }
};


// struct node{
//     TreeNode* head;
//     TreeNode* tail;
//     node(){
//         tail = head;
//     }
// };

// class Solution {
//     node *temp;
// public:
//     void helper(TreeNode* root){
        
//         if(root->left!=NULL){
//             helper(root->left);
//         }
//         if(root!=NULL){
//             TreeNode* t = new TreeNode(root->val);
//             temp->tail->right = t;
//             temp->tail->left = NULL;
//             temp->tail = temp->tail->right;
//         }
        
//         if(root->right!=NULL){
//             helper(root->right);
//         }
//     }
    
//     TreeNode* increasingBST(TreeNode* root) {
//         helper(root);
//         return temp->head;
//     }
// };