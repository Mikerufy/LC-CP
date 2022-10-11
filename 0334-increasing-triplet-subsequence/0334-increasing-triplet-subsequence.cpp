class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,0),suff(n,0);
        pre[0] = nums[0];suff[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            pre[i] = min(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1],nums[i]);
        }
        
        for(int i=1;i<n-1;i++){
            if(nums[i] < suff[i] and nums[i] > pre[i])return true;
        }
        return false;
    }
};