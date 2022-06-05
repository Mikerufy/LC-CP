class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto ans = lower_bound(nums.begin(),nums.end(),target);
        return (ans-nums.begin());
    }
};