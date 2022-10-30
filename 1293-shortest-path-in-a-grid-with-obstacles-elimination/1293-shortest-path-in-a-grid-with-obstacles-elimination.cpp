class Solution {
public:
    //up-0
    //down-1
    //left-2
    //right-3
    // long long dp[40][40][1800][4];
    long long help(vector<vector<int>>& v,int k,int i,int j,long long dir,vector<vector<vector<vector<long long>>>> &dp){
        if(i>=v.size() or j>=v[0].size() or i<0 or j<0 or v[i][j] == -1)return INT_MAX;
        if(dp[i][j][k][dir] != -1)return dp[i][j][k][dir];
        if(i==v.size()-1 and j==v[0].size()-1)return dp[i][j][k][dir] = 0;
        long long ans =0;
        if(v[i][j] == 1){
            if(k>0)
                k--;
            else return dp[i][j][k][dir] = INT_MAX;
        }
        int tmp = v[i][j];
        v[i][j] = -1;
        ans = min({1+help(v,k,i+1,j,3,dp),1+help(v,k,i,j+1,1,dp),1+help(v,k,i-1,j,2,dp),1+help(v,k,i,j-1,0,dp)});
        v[i][j] = tmp;
        return dp[i][j][k][dir] = ans;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        // memset(dp,-1,sizeof(dp));
        vector<vector<vector<vector<long long>>>> dp(grid.size(), vector<vector<vector<long long>>>(grid[0].size(), vector<vector<long long>>(k+1, vector<long long>(4,-1))));
        long long ans = help(grid,k,0,0,0,dp);
        return ans>=INT_MAX?-1:ans;
    }
};