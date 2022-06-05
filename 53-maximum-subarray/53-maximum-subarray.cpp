class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int maxtillnow = 0;
        for(int i=0;i<nums.size();i++){
            maxtillnow += nums[i];
            if(maxi < maxtillnow)
                maxi = maxtillnow;
            if(maxtillnow < 0)
                maxtillnow = 0;
        }
        return maxi;
    }
};