class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long> pre(chalk.size(),0);
        pre[0] = chalk[0];
        for(int i=1;i<chalk.size();i++){
            pre[i] = pre[i-1] + (long long)chalk[i];
        }
        k %= pre[chalk.size()-1];
        int low = 0;
        int high = chalk.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(pre[mid] <= k)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};