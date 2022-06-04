class Solution {
public:
    bool help2(vector< string>c,int col,int row){
    for(int i=0;i<row;i++){
        if(c[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(c[i][j]=='Q'){
            return false;
        }
    }
     for(int i=row-1,j=col+1;i>=0&&j<c[0].size();i--,j++){
        if(c[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
    
void help(vector<string>c,vector<vector<string>>&s , int row) {
    if(c.size()==0)return;
  if(row==c.size()){
    s.push_back(c);
      return;
  }
    
  for(int i=0;i<c[0].size();i++){
      if(help2(c,i,row)){
          c[row][i]='Q';
          help(c,s ,row+1);
          c[row][i]='.';
      }
  }
}

vector<vector<string>> solveNQueens(int n) {
        string st="";
        vector<vector<string>>v ;
        for(int i=0;i<n;i++){
            st+='.';
        }
        vector<string>s(n,st);
    
        help(s,v ,0);
        return v;
    }
};