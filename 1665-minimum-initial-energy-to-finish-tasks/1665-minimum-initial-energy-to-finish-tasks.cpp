class Solution {
public:
    static bool compare( vector<int> &a , vector<int> &b){
        return (a[1]-a[0]) > (b[1]-b[0]);
    }
    bool help(vector<vector<int>> &v,int mid){
        for(int i=0;i<v.size();i++){
            if(mid >= v[i][1] ){
                mid-=v[i][0];
            }else return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),compare);
        // reverse(tasks.begin(),tasks.end());
        int low = 1;
        int high = 1e9;
        int ans = high;
        
        while(low<=high){
            int mid = low + (high-low)/2;

            if(!help(tasks,mid)){
                low = mid+1;
            }else{
                high = mid-1;
                ans = min(ans,mid);
            }
        }
        return ans;
    }
};