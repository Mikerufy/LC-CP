class Solution {
public:
    int dp[100][100][100];
    const int mod = 1e9+7;
    int help(int m,int n,int maxi,int i,int j){
        if(i<0 or j < 0 or i >=m or j >= n)return 1;
        if(maxi <= 0 )return 0;
        if(dp[i][j][maxi] != -1)return dp[i][j][maxi];
        int x[4] = {1,0,0,-1};
        int y[4] = {0,1,-1,0};
        int ans = 0;
        for(int k=0;k<4;k++){
            int a = i+x[k];
            int b = j+y[k];
            ans = (ans + help(m,n,maxi-1,a,b))%mod;
        }
        return dp[i][j][maxi] = ans;
    }
    int findPaths(int m, int n, int maxi, int i, int j) {
        memset(dp,-1,sizeof(dp));
        int ans = help(m,n,maxi,i,j);
        return ans;
    }
};