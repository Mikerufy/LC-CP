class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        double x = log10(n)/log10(3);
        int y = x;
        if(y-x == 0)return true;
        return false;
    }
};