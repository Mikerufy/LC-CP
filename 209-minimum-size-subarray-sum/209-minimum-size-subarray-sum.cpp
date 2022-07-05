class Solution {
public:
    bool help(int mid,vector<int> &v,int t){
        int sum = 0;
        bool flag = false;
        for(int i=0;i<mid;i++){
            sum += v[i];
        }
        if(sum >=t)flag = true;
        for(int i=mid;i<v.size();i++){
            sum += v[i] - v[i-mid];
            if(sum >=t)flag = true;
        }
        
        return flag;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(help(mid,nums,target)){
                high = mid-1;
                ans = min(ans,mid);
            }else
                low = mid+1;
        }
        return ans == INT_MAX? 0 : ans;
    }
};