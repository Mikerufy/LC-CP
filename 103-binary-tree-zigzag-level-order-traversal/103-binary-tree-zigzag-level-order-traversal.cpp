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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> c;
        queue<TreeNode*> q;
        int n = 1;
        if(root){
            v.push_back({root->val});
            n++;
        }else return v;
        q.push(root);q.push(NULL);
        while(true){
            auto a = q.front();
            if(a==NULL){
                if(c.empty())break;
                if(!(n&1))
                    reverse(c.begin(),c.end());
                v.push_back(c);
                c.clear();
                q.pop();
                q.push(NULL);
                n++;
                continue;
            }    
            if(a->left){
                c.push_back(a->left->val);
                q.push(a->left);
            }
            if(a->right){
                c.push_back(a->right->val);
                q.push(a->right);
            }
                // n++;
            q.pop();
        }
        return v;
    }
};