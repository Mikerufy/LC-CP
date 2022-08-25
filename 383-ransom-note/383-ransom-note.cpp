class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int> vr(26,0),vm(26,0);
        for(auto&i : r)
            vr[i-'a']++;
        for(auto&i : m)
            vm[i-'a']++;
        
        for(int i=0;i<26;i++){
            if(vr[i]!= 0 and vr[i]> vm[i])return false;
        }
        return true;
    }
};