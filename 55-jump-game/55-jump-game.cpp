class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return true;
        int maxi = INT_MIN;
        for(int i=0;i<n-1;i++){
            maxi = max(maxi,nums[i]+i);
            if(nums[i] == 0 and maxi < (i+1))return false;
        }
        return true;
    }
};