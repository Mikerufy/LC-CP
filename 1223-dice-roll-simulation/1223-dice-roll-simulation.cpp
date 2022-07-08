class Solution {
public:
    int dp[5005][7][20];
    const int mod = 1e9+7;
    int help(int n,vector<int> &v,int i,int k,int f){
        if(i==n)return 1;
        if(dp[i][k][f] != -1)return dp[i][k][f];
        int ans = 0;
        for(int j=1;j<=6;j++){
            if(j == k and f>0){
                ans = (ans + help(n,v,i+1,j,f-1))%mod;
            }else if(j != k){
                ans = (ans+help(n,v,i+1,j,v[j-1]-1))%mod;
            }
        }
        return dp[i][k][f] = ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return help(n,rollMax,0,0,0);
    }
};