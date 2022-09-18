class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n,0),rmax(n,0);
        int tmp = 0;
        lmax[0] = 0;
        for(int i=1;i<n;i++){
            tmp = max(tmp,height[i-1]);
            lmax[i] = tmp;
        }
        tmp=0;
        rmax[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            tmp = max(tmp,height[i+1]);
            rmax[i] = tmp;
        }
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(min(lmax[i],rmax[i])-height[i]>=0)
                cnt+=min(lmax[i],rmax[i])-height[i];
        }
        return cnt;
    }
};