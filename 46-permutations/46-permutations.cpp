class Solution {
public:
    static bool check(vector<int> &a,vector<int> &b){
        reverse(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        vector<int> temp = nums;
        v.push_back(nums);
        if(nums.size() == 1)return v;
        do{
            int x = nums.size()-1;
            for(int i=nums.size()-2;i>=0;i--){
                // cout<<nums[i]<<" "<<nums[i+1]<<endl;
                if(nums[i] < nums[i+1]){
                    x = i;
                    break;
                }
            }
            int diff = INT_MAX;
            int y = x+1;
            for(int i=x+1;i<nums.size();i++){
                if((nums[x] - nums[i]) < 0 and abs(nums[i] - nums[x]) < diff){
                    diff = abs(nums[i] - nums[x]);
                    y = i;
                }
            }
            // cout<<x<<" "<<y<<endl;
            swap(nums[x],nums[y]);
            sort(nums.begin()+x+1,nums.end());
            v.push_back(nums);
        }while(!check(nums,temp));
        return v;
    }
};