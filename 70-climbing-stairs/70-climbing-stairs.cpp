class Solution {
public:
    int dp[50];
    int help(int n){
        if(dp[n]!=-1)return dp[n];
        if(n==0)return 0;
        if(n==1)return 1;
        return dp[n] = help(n-1) + help(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return help(n+1);
    }
};