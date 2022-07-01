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
    bool ans = false;
    void dfs(TreeNode* root,int t){
        if(!root)return; 
        if(t - root->val == 0 and !root->left and !root->right){
            ans = true;return;
        }
        dfs(root->left,t-root->val);
        dfs(root->right,t-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
};