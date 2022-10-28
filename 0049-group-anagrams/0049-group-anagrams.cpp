class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        map<string,vector<string>> m;
        
        for(auto&i:s){
            string tmp = i;
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto&i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};