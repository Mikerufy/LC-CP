class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0 or n==0)return false;
        double x = log(n)/log(4);
        int y = x;
        if(x-y == 0)return true;
        return false;
    }
};