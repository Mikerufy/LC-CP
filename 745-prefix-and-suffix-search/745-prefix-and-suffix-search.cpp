class WordFilter {
public:
    unordered_map<string,int> m;
    WordFilter(vector<string>& words) {
        int n = words.size();
        
        for(int i=0;i<n;i++){
            string p = "";
            for(int j=0;j<=words[i].size();j++){
                string s = "";
                for(int k=words[i].size()-1;k>=0;k--){
                    s = words[i][k] + s;
                    m[p + "-" + s] = i;
                }
                p += words[i][j];
            }
        }
    }
    
    int f(string p, string s) {
        if(m.find(p+"-"+s)!=m.end())
            return m[p+"-"+s];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */