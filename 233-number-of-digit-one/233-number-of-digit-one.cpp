class Solution {
public:
    int dp[10][10][2];
    int help(vector<int> &num,int tight,int cnt,int idx){
        if(idx >= num.size())return cnt;
        if(dp[idx][cnt][tight]!=-1)return dp[idx][cnt][tight];
        int ans = 0;
        int ub = num[idx];
        if(!tight)
            ub = 9;
        
        for(int i=0;i<=ub;i++){
            ans += help(num,(tight & (i==ub)),cnt + (i==1),idx+1);
        }
        return dp[idx][cnt][tight] = ans;
        
    }
    int countDigitOne(int n) {
        vector<int> num;
        while(n){
            num.push_back(n%10);
            n/=10;
        }
        reverse(num.begin(),num.end());
        memset(dp,-1,sizeof(dp));
        return help(num,1,0,0);
    }
};