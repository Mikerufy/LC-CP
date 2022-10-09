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
    map<int,int> m;
    bool ans = false;
    void dfs(TreeNode* root,int k){
        if(!root)return;
        if(m.find(k-root->val)!=m.end()){
            ans = true;return;
        }
        m[root->val]++;
        dfs(root->left,k);
        dfs(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
};