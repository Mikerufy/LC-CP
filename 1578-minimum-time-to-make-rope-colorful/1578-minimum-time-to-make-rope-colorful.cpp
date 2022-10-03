class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<pair<char,int>> v;
        for(int i=0;i<colors.size();i++){
            v.push_back({colors[i],neededTime[i]});
        }
        for(int i=0;i<colors.size()-1;i++){
            if(v[i].first==v[i+1].first and v[i].second > v[i+1].second)
                swap(v[i],v[i+1]);
        }
        
        int ans = 0;
        for(int i=0;i<v.size()-1;i++){
            // cout<<v[i].first<<" "<<v[i+1].first<<endl;
            if(v[i].first == v[i+1].first)
                ans+=v[i].second;
        }
        return ans;
    }
};