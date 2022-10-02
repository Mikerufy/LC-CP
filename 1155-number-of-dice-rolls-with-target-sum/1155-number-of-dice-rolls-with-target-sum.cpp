class Solution {
public:
    const int mod = 1e9+7;
    int dp[1002][32];
    int help(int idx,int n,int k,int target){
        if(idx==n){
            if(target==0)return 1;
            return 0;
        };
        if(target<=0)return 0;
        if(dp[target][idx]!=-1)return dp[target][idx];
        int ans = 0;
        for(int i=0;i<k;i++){
            ans += help(idx+1,n,k,target-(i+1));
            ans = ans%mod;
        }
        return dp[target][idx] = ans;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return help(0,n,k,target);
    }
};