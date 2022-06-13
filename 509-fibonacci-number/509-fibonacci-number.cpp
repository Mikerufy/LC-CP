class Solution {
public:
    int help(int n){
        if(n==1)return 1;
        if(n==0)return 0;
        return help(n-1) + help(n-2);
    }
    int fib(int n) {
        return help(n);
    }
};