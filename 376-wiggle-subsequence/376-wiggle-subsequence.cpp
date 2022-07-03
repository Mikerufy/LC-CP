class Solution {
public:
    int dp[1003][2];
    int help(vector<int> &v,int n,int i,int flag){
        if(i >= n)return 0;
        if(dp[i][flag] != -1)return dp[i][flag];
        int one = 0,two = 0;
        if(flag){
            if(i< n-1 and v[i+1] - v[i] < 0)
                one = 1 + help(v,n,i+1,0);
            two = help(v,n,i+1,1);
        }else{
            if(i< n-1 and v[i+1] - v[i] > 0)
                one = 1 + help(v,n,i+1,1);
            two = help(v,n,i+1,0);
        }
        return dp[i][flag] = max(one,two);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        if(nums.size() == 1)return 1;
        int one = 0;
        int i = 1;
        while(i< nums.size() and nums[i] - nums[i-1]==0)i++;
        if(i >=nums.size())return 1;
            one = 1 + help(nums,nums.size(),i,(nums[i]-nums[i-1] > 0));
        int two = help(nums,nums.size(),i,0);
        return max(one,two) + 1;
    }
};