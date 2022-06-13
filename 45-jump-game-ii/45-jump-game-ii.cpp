class Solution {
public:
    int dp[100004];
    int help(vector<int>& v,int i){
        if(dp[i] != -1)return dp[i];
        if(i>=(v.size()-1))return 0;
        int ans = INT_MAX-1;
        for(int j=1;j<= v[i];j++){
            ans = min(ans,1 + help(v,i+j));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return help(nums,0);
    }
};