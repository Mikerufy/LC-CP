class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),compare);
        int ans = 0;
        for(int i=0;i<b.size();i++){
            if(t<=0)break;
            if(t - b[i][0] > 0){
                ans+= (b[i][0]*b[i][1]);
                t-= b[i][0];
            }else{
                ans+= (b[i][1]*t);
                t=0;
            }
        }
        return ans;
    }
};