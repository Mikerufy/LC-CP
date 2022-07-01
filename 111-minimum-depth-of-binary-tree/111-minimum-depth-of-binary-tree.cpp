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
    int dfs(TreeNode* root){
        if(!root)return 0;
        if(!root->left and !root->right)return 1;
        int one = INT_MAX;
        int two = INT_MAX;
        if(root->left)one = 1 + dfs(root->left);
        if(root->right)two = 1 + dfs(root->right);
        return min(one,two);
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};