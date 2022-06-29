class Solution {
public:
    int dp[1003][400];
    int help(vector<int> &v,int n,int t,int i,int amt){
        if(i == n)return 0;
        if(t == amt){
           return 1;
        }
        if(amt > t)return 0;
        if(dp[amt][i] != -1)return dp[amt][i];

        
        int one = help(v,n,t,0,amt + v[i]);
        int two = help(v,n,t,i+1,amt);
        return dp[amt][i] = one+two;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return help(nums,nums.size(),target,0,0);
    }
};