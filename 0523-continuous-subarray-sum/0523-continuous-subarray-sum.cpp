class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size(),0);
        pre[0] = nums[0];
        map<int,int> s;
        s[pre[0]%k] = 0;
        s[0] = -1;//IMP had to refer discuss;
        for(int i=1;i<nums.size();i++){
            pre[i] = pre[i-1] + nums[i];
            int mod = pre[i]%k;
            if(s.find(mod)!=s.end() )
            {
                if(i - s[mod] > 1)
                    return true;
            }
            else s[mod] = i;
        }
        return false;
    }
};