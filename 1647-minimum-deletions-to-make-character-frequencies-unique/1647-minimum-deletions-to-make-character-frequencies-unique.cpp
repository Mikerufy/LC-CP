class Solution {
public:
    static bool compare(int a,int b){
        return a>b;
    }
    int minDeletions(string s) {
        vector<int> m(26,0);
        for(int i=0;i<s.size();i++){
            m[s[i]-'a']++;
        }
        
        sort(m.begin(),m.end());
        int cnt = 0;
        for(int i=24;i>=0;i--){
            if(m[i] == 0)break;
            if(m[i] >= m[i+1]){
                int prev = m[i];
                m[i] = max(0,m[i+1] -1);
                cnt += prev - m[i];
            }
        }
        return cnt;
    }
};