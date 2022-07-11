class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i] - x),i});
        }
        vector<int> ans;
        while(k--){
            int a = arr[pq.top().second];
            ans.push_back(a);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};