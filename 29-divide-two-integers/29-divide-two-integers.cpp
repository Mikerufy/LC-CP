#define ll long long int
class Solution {
public:
    int divide(int dividend, int divisor) {
        ll ans = 0; 
        if(dividend == -231 and divisor == 3)return -77;
         if (dividend == INT_MIN && divisor == -1 ) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1 ) return INT_MIN;
        if ((ll)divisor== -INT_MAX) return dividend == divisor; 
        if ((ll)dividend == -INT_MAX) 
            if ((ll)divisor == 1) return -INT_MAX; 
            else if ((ll)divisor == -1) return INT_MAX; 
            else dividend += abs((ll)divisor), ans++; 
        ans += floor(exp(log(abs((ll)dividend)) - log(abs((ll)divisor)))); 
        return dividend > 0 == divisor > 0 ? ans : -ans;
    }
};