class Solution {
public:
    bool help(string s){
        string b = s;
        reverse(b.begin(),b.end());
        return b==s;
    }
    int removePalindromeSub(string s) {
        if(help(s))return 1;
        return 2;
    }
};