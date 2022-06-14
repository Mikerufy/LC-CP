class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp,0,sizeof(dp));
        int m = word1.size();
        int n = word2.size();
        for(int i=1;i<word1.size()+1;i++){
            for(int j=1;j<word2.size()+1;j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (abs(m-dp[m][n]) + abs(n-dp[m][n]));
    }
};