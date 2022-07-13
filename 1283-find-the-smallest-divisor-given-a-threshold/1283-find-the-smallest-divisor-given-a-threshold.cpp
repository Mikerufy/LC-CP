class Solution {
public:
    bool help(vector<int> &v,int t, int mid){
        int sum = 0;
        for(int i=0;i<v.size();i++){
            sum += ceil(v[i]*1.0/mid);
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int low = 1;
        int high = 1e9;
        int ans= high;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(!help(nums,t,mid)){
                low = mid+1;
            }else{
                ans = min(ans,mid);
                high = mid -1;
            }
        }
        return ans;
    }
};