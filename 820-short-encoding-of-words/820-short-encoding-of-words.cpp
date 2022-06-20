class Solution {
public:
    static bool compare(string a,string b){
        return a.size()>b.size();
    }
    int minimumLengthEncoding(vector<string>& w) {
        // sort(w.begin(),w.end(),compare);
        int cnt = 0;
        map<string,int> m;
        for(int i=0;i<w.size();i++){
            int n = w[i].size();
            for(int j=1;j<n;j++){
                string s = w[i].substr(j);
                m[s]++;
            }
        }
        
        for(int i=0;i<w.size();i++){
            if(m.find(w[i])!=m.end()){
                continue;
            }else{
                cnt+= w[i].size()+1;
                m[w[i]]++;
            }
        }
        return cnt;
    }
};