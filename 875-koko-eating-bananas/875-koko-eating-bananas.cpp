class Solution {
public:
    bool help(int k,vector<int> &v,int h){
        int cnt = 0;
        for(int i=0;i<v.size();i++){
            cnt += ceil((double)v[i]/k);
            if(cnt>h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int low = 1;
        int high = *max_element(p.begin(),p.end());
        
        while(low<=high){
            int mid = (low+high)/2;
            if(help(mid,p,h)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};