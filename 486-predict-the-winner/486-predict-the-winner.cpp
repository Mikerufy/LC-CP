class Solution {
public:
    int help(vector<int> &nums,int i,int j,int flag){
        if(i>j)return 0;
        int one=0,two=0;
        if(flag==1){
            return max(help(nums,i+1,j,0)+nums[i],help(nums,i,j-1,0)+nums[j]);
        }else{
            return min(help(nums,i+1,j,1),help(nums,i,j-1,1));
        }
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int p1 = help(nums,0,nums.size()-1,1);
        int p2 = accumulate(nums.begin(),nums.end(),0)-p1;
        return p1>=p2;
    }
};