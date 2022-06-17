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
    int cnt = 0;
    int dfs(TreeNode* root){
        if(!root)return -1;
        int one = dfs(root->left);
        int two = dfs(root->right);
        
        if(one == 0 or two == 0){
            cnt++;
            return 1;
        }
        if(one == 1 or two == 1){
            return -1;
        }
        else{
            return 0;
        }
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==0)return ++cnt;
        return cnt;
    }
};