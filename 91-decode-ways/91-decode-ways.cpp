class Solution {
public:
    int dp[102];
    int dpf(string &s,int i,int n){
        if(i == n)return 1;
        if(s[i] == '0')return dp[i] = 0;
        if(dp[i] != -1)return dp[i];
        int one = (dpf(s,i+1,n));
        int two = 0;
        if(i< n-1 and (s[i] == '1' or  (s[i] =='2' and s[i+1] <='6')))
            two = (dpf(s,i+2,n));
        return dp[i] = one+two;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return dpf(s,0,s.size());
    }
};