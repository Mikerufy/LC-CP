/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(!root) return ans;
        q.push(root);
        while(q.size()){
            int n = q.size();
            vector<int> v;
            while(n--){
                auto x = q.front();
                q.pop();
                for(auto&i:x->children)
                    q.push(i);
                v.push_back(x->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};