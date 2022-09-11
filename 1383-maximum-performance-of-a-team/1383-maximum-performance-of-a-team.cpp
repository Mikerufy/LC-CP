class Solution {
public:
    const int mod = 1e9+7;
    static bool compare(pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    }
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int,int>> v;
        
        for(int i=0;i<s.size();i++){
            v.push_back({e[i],s[i]});
        }
        sort(v.begin(),v.end(),compare);
        // reverse(v.begin(),v.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        long long int sum = 0;
        long long int ans = 0;
        for (int i = 0; i < k; i++) {
            sum += v[i].second;
            ans = max(ans, sum*v[i].first);
            pq.push(v[i].second);
        }
        for (int i = k; i < n; i++) {
            if (v[i].second > pq.top()) {
                sum += (-pq.top()+v[i].second);
                ans = max(ans, sum*v[i].first);
                pq.pop();
                pq.push(v[i].second);
            }
        }
        return ans%mod;
    }
};