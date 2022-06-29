class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return a[0]>b[0] or (a[0] == b[0] and a[1]<b[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        vector<vector<int>> ans;
        sort(p.begin(),p.end(),compare);
        for(int i=0;i<p.size();i++){
            ans.insert(ans.begin()+p[i][1],p[i]);
        }
        return ans;
    }
};