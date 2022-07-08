#define ll long long int
class Solution {
public:
    int dp[10005][8][8];
    const int mod = 1e9+7;
    ll gcd(ll a, ll b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int help(int n,int i,int k,int m){
        if(i== n)return 1;
        if(dp[i][k][m] != -1)return dp[i][k][m];
        int ans = 0;
        for(int j=1;j<=6;j++){
            if((gcd(k,j)== 1 or k == 7)  and j != k and j!=m){
                ans = (ans + help(n,i+1,j,k))%mod;
            }
            
        }
        return dp[i][k][m] = ans%mod;
    }
    int distinctSequences(int n) {
        memset(dp,-1,sizeof(dp));
        return help(n,0,7,7);
    }
};