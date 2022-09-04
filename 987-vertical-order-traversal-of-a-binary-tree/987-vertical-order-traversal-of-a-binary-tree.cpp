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
    void dfs(map<int,map<int,vector<int>>>& m,TreeNode* root, int h,int w){
        if(root==NULL)return;
        if(m.find(w)==m.end()){
            map<int,vector<int>> temp;
            temp[h] = {root->val};
            m[w] = temp;
        }
        else{
            if(m[w].find(h)==m[w].end()){
                m[w][h] = {root->val};
            }
            else m[w][h].push_back(root->val);
        }
        dfs(m,root->right,h+1,w+1);
        dfs(m,root->left,h+1,w-1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        vector<vector<int>> ans;
        dfs(m,root,0,0);
        for(auto& p:m){
            auto map = p.second;
            vector<int> temp;
            for(auto& pa:map){
                auto vec = pa.second;
                sort(vec.begin(),vec.end());
                for(auto& val:vec){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};