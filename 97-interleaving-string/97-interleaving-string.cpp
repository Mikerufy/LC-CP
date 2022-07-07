class Solution {
public:
    int dp[103][103];
    bool help(string &s1,string &s2,string &s3,int i,int j,int k){
        if(i == s1.size() and j == s2.size() and k == s3.size())return true;
        if(i>s1.size() or j > s2.size())return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool one=false;
        if(s1[i] == s3[k] and s2[j] == s3[k]){
            one = help(s1,s2,s3,i+1,j,k+1) or help(s1,s2,s3,i,j+1,k+1);
        }else if(s1[i] == s3[k]){
            one = help(s1,s2,s3,i+1,j,k+1);
        }else if(s2[j] == s3[k]){
            one = help(s1,s2,s3,i,j+1,k+1);
        }
        return dp[i][j] = one;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return help(s1,s2,s3,0,0,0);
    }
};