class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int mini = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int l = i+1,h=n-1;
            while(l<h){
                int sum = nums[i] + nums[l] + nums[h];
                if(sum==target)
                    return sum;
                if(sum<target)
                    l++;
                else h--;
                
                if(mini > abs(target-sum)){
                    mini = abs(target-sum);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};