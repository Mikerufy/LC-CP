class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int k = lower_bound(nums.begin()+j+1,nums.end(),nums[i]+nums[j])-nums.begin();
                cnt += k-j-1;
            }
        }
        return cnt;
    }
};