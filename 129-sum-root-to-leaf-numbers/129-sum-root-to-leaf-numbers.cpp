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
    int ans = 0;
    void help(TreeNode* root,string s){
        
        if(!root->left and !root->right){
            ans+= stoi(s+to_string(root->val));
            return;
        }
        if(root->left){
            help(root->left,s+to_string(root->val));
        }
        if(root->right){
            help(root->right,s+to_string(root->val));
        }
        
    }
    int sumNumbers(TreeNode* root) {
        help(root,"");
        return ans;
    }
};