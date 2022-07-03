class Solution {
public:
    bool help(int mid,vector<int> &p,int m){
        int last = p[0];
        for(int i=1;i<p.size();i++){
            if(abs(last - p[i])>=mid and m>1){
                last = p[i];
                m--;
            }
        }
        return m==1;
    }
    int maxDistance(vector<int>& p, int m) {
        int n = p.size();
        sort(p.begin(),p.end());
        int low = 1;
        int high = *max_element(p.begin(),p.end());
        
        int maxi = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(help(mid,p,m)){
                maxi = max(maxi,mid);
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return maxi;
    }
};