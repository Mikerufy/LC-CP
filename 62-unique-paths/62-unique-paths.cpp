class Solution {
public:
    int dp[101][101];
    int help(int i,int j,int m,int n){
        if(i==m or j==n)return 0;
        if(i==m-1 and j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int one =  help(i+1,j,m,n);
        int two =  help(i,j+1,m,n);
        
        return dp[i][j] = one+two;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return help(0,0,m,n);
    }
};