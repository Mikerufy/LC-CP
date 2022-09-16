class Solution {
public:
    int dp[1000][1000];
    int help(vector<int> &nums,vector<int> &m,int i,int j,int k){
        if(k== m.size())return 0;
        if(dp[i][k]!=INT_MAX)return dp[i][k];
        int one=0,two=0;
        one = help(nums,m,i+1,j,k+1) + nums[i]*m[k];
        two = help(nums,m,i,j-1,k+1) + nums[j]*m[k];
        
        return dp[i][k] = max(one,two);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for(int i=0;i<1000;i++){
            for(int j=0;j<1000;j++){
                dp[i][j] = INT_MAX;
            }
        }
        return help(nums,multipliers,0,nums.size()-1,0);
    }
};