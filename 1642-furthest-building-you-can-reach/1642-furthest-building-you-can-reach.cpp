class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=1;i<h.size();i++){
            if(h[i] - h[i-1] <0)continue;
            pq.push(h[i] - h[i-1]);
            if(pq.size() <= l)continue;
            int x = pq.top();
            pq.pop();
            b-=x;
            if(b<0)return i-1;
            
        }
        return h.size()-1;
    }
};