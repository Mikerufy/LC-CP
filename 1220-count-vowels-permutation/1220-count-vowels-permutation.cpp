class Solution {
public:
    string k = "aeoui";
    const int mod = 1e9+7;
    int dp[20006][26];
    int help(int n,int i,char x){
        if(i==n)return 1;
        if(i>n)return 0;
        int one = 0;
        if(dp[i][x-'a']!=-1)return dp[i][x-'a'];
        if(x=='a'){
            one += help(n,i+1,'e');
            one = one%mod;
        }
        else if(x=='e'){
            one += help(n,i+1,'a') + help(n,i+1,'i');
            one = one%mod;
        }
        else if(x=='i'){    
            for(int j=0;j<4;j++){
                one+= help(n,i+1,k[j]);
                one = one%mod;
            }
        }
        else if(x=='o'){
            one += help(n,i+1,'i') + help(n,i+1,'u');
            one = one%mod;
        }
        else if(x=='u'){
            one += help(n,i+1,'a');
            one = one%mod;
        }
        return dp[i][x-'a'] = one;
        
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        string s = "";
        int ans = 0;
        for(int j=0;j<5;j++){
            ans+= help(n,1,k[j]);
            ans = ans%mod;
        }
        return ans;
    }
};