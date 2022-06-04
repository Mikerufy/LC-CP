class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        auto x = lower_bound(nums.begin(),nums.end(),target);
        auto y = lower_bound(nums.begin(),nums.end(),target+1);
        if((x-nums.begin()) > nums.size()-1 or (x-nums.begin()) == (y-nums.begin())){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        
        v.push_back(x-nums.begin());
        v.push_back((y-nums.begin())-1);
        return v;
    }
};