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
    bool dfs(TreeNode* root,long long l,long long r){
        if(!root)return true;
        if(l > root->val or r < root->val)return false;
        bool left = dfs(root->left,l,root->val -1LL);
        bool right = dfs(root->right,root->val+1LL,r);
        return (left and right);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,-1e11,1e11);
    }
};