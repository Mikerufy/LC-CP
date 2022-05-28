#define ll long long int
class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        ll ans = 0;
        string s = to_string(n);
        std::reverse(s.begin(),s.end());
        while(s[0]==0)
            s=s.substr(1);
        ans = stol(s);
        if(ans>INT_MAX)
            return 0;
        if(x<0)
        {
            return -ans;
        }
        return ans;
    }
};