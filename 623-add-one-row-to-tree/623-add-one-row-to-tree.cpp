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
    void help(TreeNode* root,int val,int d,int lvl){
        if(!root)return;
        if(lvl == d-1){       
            if(root->left == NULL){     
            root->left = new TreeNode(val);       
            }
            else{           
                TreeNode* temp = root->left;
                root->left = new TreeNode(val);
                root->left->left = temp;
            
            }       
            if(root->right == NULL){           
                root->right = new TreeNode(val);       
            }
            else{          
                TreeNode* temp = root->right;
                root->right = new TreeNode(val);
                root->right->right = temp ;           
            }
            return;
        }
        help(root->left,val,d,lvl+1);
        help(root->right,val,d,lvl+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if(depth == 1){
            
            TreeNode* temp = root ;
            root = new TreeNode(val);
            root->left = temp;
            return root ;
            
        }
        help(root,val,depth,1);
        return root;
    }
};