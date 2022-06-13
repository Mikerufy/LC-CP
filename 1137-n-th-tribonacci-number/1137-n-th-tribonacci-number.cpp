class Solution {
public:
    int dp[38];
    int help(int n){
        if(dp[n] != -1)return dp[n];
        if(n==1 or n==2)return 1;
        if(n==0)return 0;
        return dp[n] = help(n-1)+help(n-2)+help(n-3);
    }
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return help(n);
    }
};