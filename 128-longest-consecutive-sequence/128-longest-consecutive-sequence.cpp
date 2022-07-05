class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uset(nums.begin(),nums.end());
        int prev = 0,next=0,result=0;
        for(int i=0;i<n;i++)
        {
            if(uset.find(nums[i])!= uset.end())
            {
                prev = nums[i]-1;
                next = nums[i]+1;
                uset.erase(nums[i]);
                while(uset.find(prev)!=uset.end())
                {
                    uset.erase(prev);
                    prev--;
                }
                while(uset.find(next)!=uset.end())
                {
                    uset.erase(next);
                    next++;
                }
                result = max(result,next-prev-1);
            }
        }
        return result;
    }
};