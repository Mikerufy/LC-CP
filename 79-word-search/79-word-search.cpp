class Solution {
public:
    bool help(vector<vector<char>> &v,string &s,int i,int j,int k){
        if(k == s.size())return true;
        if(i<0 or j<0 or i>= v.size() or j>= v[0].size())return false;
        if(s[k] != v[i][j])return false;
        
        v[i][j] = '.';
        bool ans = help(v,s,i+1,j,k+1) or help(v,s,i-1,j,k+1) or help(v,s,i,j+1,k+1) or help(v,s,i,j-1,k+1);
        v[i][j] = s[k];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                ans |= help(board,word,i,j,0);
            }
        }
        return ans;
    }
};