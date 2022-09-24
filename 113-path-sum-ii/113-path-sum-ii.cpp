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
    vector<vector<int>> result;
    void help(TreeNode* root,int targetSum,vector<int> curr)
    {
        if(!root)
            return;
        curr.push_back(root->val);
        int sum = 0;
        for(int i=0;i<curr.size();i++)
        {
            sum+=curr[i];
        }
        if(!root->left && !root->right)
        {
            if(sum == targetSum)
            {
                result.push_back(curr);
                return;
            }
        }
        help(root->left,targetSum,curr);
        help(root->right,targetSum,curr);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        help(root,targetSum,curr);
        return result;
    }
};