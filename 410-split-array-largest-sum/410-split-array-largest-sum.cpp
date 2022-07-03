class Solution {
public:
    bool help(vector<int> &nums,int m,int mid){
        int sum = 0;
        int cnt = 1;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i] <= mid and m>1){
                sum+= nums[i];
            }else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(help(nums,m,mid)){
                high = mid-1;
                ans = min(ans,mid);
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};