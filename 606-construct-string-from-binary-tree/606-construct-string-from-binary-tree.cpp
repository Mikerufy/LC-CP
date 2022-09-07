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
    void help(TreeNode* root,string &s){
        if(!root)return;
        s+=to_string(root->val);
        if(!root->left and root->right){
            s+="()";
        }
        if(root->left){
            s += "(";
            help(root->left,s);
            s+= ")";
        }
        if(root->right){
            s += "(";
            help(root->right,s);
            s+= ")";
        }
        return;
    }
    string tree2str(TreeNode* root) {
        string s="";
        help(root,s);
        return s;
    }
};