class Solution {
public:
    bool help(vector<int> &v,int i,int k,int t,int curr,vector<bool> &vis){
        if(k==1)return true;
        
        if(curr == t)
            return help(v,0,k-1,t,0,vis);
        
        for(int j=i;j<v.size();j++){
            if(vis[j] or curr + v[j] > t)continue;
            vis[j] = true;
            if(help(v,j+1,k,t,curr+v[j],vis))return true;
            vis[j]=false;
        }
        return false;
        
             
    }
    bool makesquare(vector<int>& m) {
        int sum = accumulate(m.begin(),m.end(),0);
        if(sum%4!=0)return false;
        vector<bool> vis(m.size(),false);
        return help(m,0,4,sum/4,0,vis);
    }
};