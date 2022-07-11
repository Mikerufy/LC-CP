class Solution {
public:
    bool help(vector<int> &v,int maxi,int mid){
        int cnt = 0;
        for(int i=0;i<v.size();i++){
            cnt += (v[i]-1)/mid;
        }
        return cnt <= maxi;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = 1e9;
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(!help(nums,maxOperations,mid)){
                low = mid+1;
            }else{
                ans = min(ans,mid);
                high = mid-1;
            }
        }
        return ans;
    }
};