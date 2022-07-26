/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* help(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = help(root->left, p, q);
        TreeNode* right = help(root->right, p, q);
        if(left && right)
            return root;
        if(!left)
            return right;
        return left;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return help(root, p, q);
    }
};