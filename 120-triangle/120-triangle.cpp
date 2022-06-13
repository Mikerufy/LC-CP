class Solution {
public:
    int dp[202][202];
    int recurr(vector<vector<int>> &v,int i,int j){
        if(dp[i][j] != -1)return dp[i][j];
        if(i == v.size()-1)return v[i][j];
        
        int one = v[i][j] + recurr(v,i+1,j);
        int two = v[i][j] + recurr(v,i+1,j+1);
        
        return dp[i][j] = min(one,two);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        int ans = recurr(triangle,0,0);
        return ans;
    }
};