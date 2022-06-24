class Solution {
public:
    int dp[1000];
    int help(vector<int> &v,int n,int i){
        if(dp[i]!=-1)return dp[i];
        if(i>=n)return 0;
        int one = help(v,n,i+2) + v[i];
        int two = help(v,n,i+1);
        return dp[i] = max(one,two);
        
        
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        memset(dp,-1,sizeof(dp));
        int maxi = help(nums,nums.size()-1,0);
        memset(dp,-1,sizeof(dp));
        return max(maxi,help(nums,nums.size(),1));
    }
};