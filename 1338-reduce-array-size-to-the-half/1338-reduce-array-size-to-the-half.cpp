class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        priority_queue< pair<int,int> > pq;
        int n = arr.size();
        unordered_map<int,int> mp;
      
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto x : mp)
        {
            pq.push({x.second,x.first});
        }
        
        int mid = n/2;
        int sum = 0;
        int c=0;
        while(sum < mid)
        {
            sum+=pq.top().first;
            pq.pop();
            c++;
        }
        return c;
    }
};