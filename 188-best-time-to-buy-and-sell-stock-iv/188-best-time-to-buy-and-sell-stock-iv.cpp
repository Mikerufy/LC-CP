class Solution {
public:
    int dp[1002][2][103];
    int help(vector<int> &v,int n,int k,int i,int flag,int cnt){
        if(dp[i][flag][cnt] != -1)return dp[i][flag][cnt];
        if(i>=n or cnt == k)return 0;
        int ans = 0;
        if(!flag){
            int one = help(v,n,k,i+1,1,cnt) - v[i];
            int two = help(v,n,k,i+1,0,cnt);
            ans = max(one,two);
        }else{
            int one = help(v,n,k,i+1,0,cnt+1) + v[i];
            int two = help(v,n,k,i+1,1,cnt);
            ans = max(one,two);
        }
        return dp[i][flag][cnt] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return help(prices,prices.size(),k,0,0,0);
    }
};