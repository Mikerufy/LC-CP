class Solution {
public:
    bool checkIfPangram(string s) {
        set<char> ss;
        for(int i=0;i<s.size();i++){
            ss.insert(s[i]);
        }
        return ss.size()==26;
    }
};