class Solution {
public:
    int dp[4*10004][3];
    int help(vector<int> &v,int n,int i,int flag){
        if(dp[i][flag] != -1)return dp[i][flag];
        if(i >= n){
            return 0;
        }
        int ans = 0;
        if(!flag){
            int one = help(v,n,i+1,1) - v[i];
            int two = help(v,n,i+1,0);
            ans = max(one,two);
        }else{
            int one = help(v,n,i+1,0) + v[i];
            int two = help(v,n,i+1,1);
            ans = max(one,two);
        }
        return dp[i][flag] = ans;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        int ans = help(prices,n,0,0);
        return ans;
    }
};