class Solution {
public:
    static int msb(int n){
       int msb=-1;
        
        while(n)
        {
            n>>=1;
            msb++;
        }
        return msb;
    }
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        if(!left or !right)return 0;
        while(left and right){
            int msb1=msb(left);
            int msb2=msb(right);
            
            if(msb1!=msb2)break;
            
            int temp = 1<<msb1;
            ans+=temp;
            left-=temp;
            right-=temp;
        }
        return ans;
    }
};