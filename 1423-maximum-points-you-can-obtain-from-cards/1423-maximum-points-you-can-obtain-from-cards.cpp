class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        //Memory Limit exceeds so DP wont work :(
        // Sliding Window-->
        
        int left=0,right=0,n=cp.size();
        for(int i=n-k;i<n;i++){
            right+=cp[i];
        }
        left = right;
        for(int i=0;i<k;i++){
            left -= cp[n-k+i];
            left += cp[i];
            right = max(right,left);
        }
        return right;
    }
};