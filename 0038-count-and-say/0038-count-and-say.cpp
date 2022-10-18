class Solution {
public:
    string help(int n,int idx,string s){
        if(idx>n)return s;
        if(idx == 1) return help(n,idx+1,s+"1");
        else
        {
            string tmp="";
            int cnt = 1;
            for(int i=1;i<s.size();i++){
                if(s[i]==s[i-1]){
                    cnt++;
                }else{
                    tmp+= to_string(cnt)+s[i-1];
                    cnt=1;
                }
                // cout<<s[i]<<endl;
            }
            if(cnt>=1)
            {
                tmp+=to_string(cnt)+s[s.size()-1];
            }
            // cout<<tmp<<endl;
            return help(n,idx+1,tmp);
        }
    }
    string countAndSay(int n) {
        return help(n,1,"");
    }
};