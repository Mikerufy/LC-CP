class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(low<=high){
            if(nums[low] == 2){
                swap(nums[low],nums[high--]);
            }else if(nums[low] == 0){
                swap(nums[low++],nums[mid++]);
            }else if(nums[low] == 1){
                low++;
            }
        }
        
    }
};