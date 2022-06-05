class Solution {
public:
    static bool check(vector<vector<bool>> &v,int row,int col,int n){
        if(v[row][col])return false;
        for(int i=0;i<=row;i++){
            if(v[i][col])return false;
            if(row-i>=0 and col-i>=0 and v[row-i][col-i])return false;
            if(row-i>=0 and col+i<n and v[row-i][col+i])return false;

        }
        return true;
    }
    static int help(vector<vector<bool>> &v,int row,int n){
        if(row == n)return 1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(check(v,row,i,n)){
                v[row][i] = true;
                cnt += help(v,row+1,n);
                v[row][i] = false;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<vector<bool>> v(n,vector<bool>(n,false));
        int ans = help(v,0,n);
        return ans;
    }
};