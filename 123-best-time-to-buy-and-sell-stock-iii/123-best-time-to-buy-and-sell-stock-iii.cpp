class Solution {
public:
    int dp[100004][2][2];
    int help(vector<int> &v,int n,int i,int flag,int cnt){
        if(cnt>=2){
            return 0;
        }
        if(dp[i][flag][cnt] != -1)return dp[i][flag][cnt];
        if(i >= n){
            return 0;
        }
        int ans = 0;
        if(!flag){
            int one = help(v,n,i+1,1,cnt) - v[i];
            int two = help(v,n,i+1,0,cnt);
            ans = max(one,two);
        }else{
            int one = help(v,n,i+1,0,cnt+1) + v[i];
            int two = help(v,n,i+1,1,cnt);
            ans = max(one,two);
        }
        return dp[i][flag][cnt] = ans;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        int ans = help(prices,n,0,0,0);
        return ans;
    }
};