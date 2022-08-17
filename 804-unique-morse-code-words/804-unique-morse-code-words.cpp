class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vec ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set <string> s;
        string tmp;
        for(int i=0;i<words.size();i++){
            tmp = "";
            for(int j=0;j<words[i].length();j++)
                tmp += vec[words[i][j] - 'a'];
            s.insert(tmp);
        }
        return s.size();
    }
};