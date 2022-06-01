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
    int maxDepth(TreeNode* root) {
        int cnt = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        if(root==NULL)return 0;
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            cnt = max(cnt,a.second);
            if(a.first->left){
                q.push({a.first->left,a.second + 1});
            }
            if(a.first->right){
                q.push({a.first->right,a.second + 1});
            }
        }
        return cnt;
    }
};