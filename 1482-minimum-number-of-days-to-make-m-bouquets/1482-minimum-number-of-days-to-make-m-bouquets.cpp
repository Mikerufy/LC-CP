class Solution {
public:
    bool help(vector<int> &v,int m,int k,int mid){
        int cnt = 0;
        int x = 0;
        for(int i=0;i<v.size();i++){
            if(v[i] > mid){
                x=0;
            }else if(++x >= k){
                x=0;
                cnt++;
            }
        }
        return cnt >= m;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size())return -1;
        int low = 0;
        int high = 1e9;
        int ans = high;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(!help(bloomDay,m,k,mid)){
                low = mid + 1;
            }else{
                high = mid - 1;
                ans = min(ans,mid);
            }
        }
        return ans;
    }
};