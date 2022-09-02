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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> pending;
        pending.push(root);
        vector<double> ans = {(double)root->val};
        while(!pending.empty()){
            int n = pending.size();
            double count=0, temp=0;
            for(int i=0; i<n; i++){
                TreeNode* front = pending.front();
                pending.pop();
                
                if(front->right!=NULL){
                    temp += front->right->val;
                    pending.push(front->right);
                    count++;
                }
                if(front->left!=NULL){
                    temp += front->left->val;
                    pending.push(front->left);
                    count++;
                }
            }
            if(count!=0) ans.push_back(temp/count);
        }
        return ans;
    }
};