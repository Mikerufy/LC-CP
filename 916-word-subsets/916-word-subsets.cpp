class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> mp;
        for(int i=0; i<words2.size(); i++){
            map<char, int> temp;
            for(int j=0; j<words2[i].size(); j++){
                temp[words2[i][j]]++;
            }
            for(auto x:temp){
                if(x.second>mp[x.first]) mp[x.first]=x.second;
                else continue;
            }
        }
        
        vector<string> res;
        for(int i=0; i<words1.size(); i++){
            map<char, int> words;
            for(int j=0; j<words1[i].size(); j++){
                words[words1[i][j]]++;
            }
            int valid=1;
            for(auto x: mp){
                if(x.second>words[x.first]){
                    valid=0;
                    break;
                }
            }
            if(valid==1) res.push_back(words1[i]);
        }
        return res;
    }
};