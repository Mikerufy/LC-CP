class Solution {
public:
    long long dp[103][103][103];
    int help(vector<int> &houses,vector<vector<int>> &cost,int i,int m,int n,int t,int prev){
        if(t < 0)return INT_MAX;
        if(i == m){
            if(t == 0)return 0;
            else return INT_MAX;
        }
        
        if(dp[i][prev][t] != -1)return dp[i][prev][t];
        
        if(houses[i] != 0){
            return dp[i][prev][t] = help(houses,cost,i+1,m,n,t-(houses[i] != prev),houses[i]);
        }
        long long ans = INT_MAX;
        for(int j=0;j<n;j++){
            ans = min(ans,(long long)cost[i][j] + (long long)help(houses,cost,i+1,m,n,t-(j+1 != prev),j+1));
        }
        return dp[i][prev][t] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = help(houses,cost,0,m,n,target,101);
        return ans==INT_MAX?-1:ans;
        
    }
};