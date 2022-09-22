class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        while(i<s.size()){
            int j=i;
            string x="";
            while(j<s.size() and s[j]!=' '){
                x+=s[j];
                j++;
            }
            i=j+1;
            reverse(x.begin(),x.end());
            ans+=x;
            if(!(j>=s.size()))
                ans+=" ";
        }
        return ans;
    }
};