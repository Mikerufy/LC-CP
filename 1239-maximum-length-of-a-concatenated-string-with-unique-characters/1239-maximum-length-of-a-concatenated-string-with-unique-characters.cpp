class Solution {
public:
    int ans = 0;
    bool check2(vector<string> &v){
        set<char> st;
        string tmp="";
        for(auto&i:v)
            tmp+=i;
        for(auto&i:tmp)
            st.insert(i);
        return st.size()==tmp.size();
    }
    void check(vector<string> &v){
        set<char> st;
        string tmp="";
        for(auto&i:v)
            tmp+=i;
        for(auto&i:tmp)
            st.insert(i);
        if(st.size()==tmp.size())
            ans=max(ans,(int)tmp.size());
    }
    void help(vector<string> &v,int idx,int n,vector<string> &x){
        if(idx>=n)return;
        if(!check2(x))return;
        x.push_back(v[idx]);
        help(v,idx+1,n,x);
        check(x);
        x.pop_back();
        help(v,idx+1,n,x);
        
    }
    int maxLength(vector<string>& arr) {
        vector<string> x;
        help(arr,0,arr.size(),x);
        return ans;
    }
};