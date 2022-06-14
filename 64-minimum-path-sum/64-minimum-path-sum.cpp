class Solution {
public:
    int dp[202][202];
    int help(vector<vector<int>>& v,int x,int i,int j){
        if(dp[i][j] != -1)return dp[i][j];
        if(i == v.size()-1 and j == v[0].size()-1)return v[i][j];
        if(i>= v.size())return 10000;
        if(j>= v[0].size())return 10000;
        int one = v[i][j] + help(v,x,i+1,j);
        int two = v[i][j] + help(v,x,i,j+1);
        
        x = min(one,two);
        return dp[i][j] = x;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return help(grid,0,0,0);
    }
};