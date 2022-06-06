class Solution {
public:
    static int help(int n)
    {
        if (n <= 1)
            return 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += help(i) * help(n - i - 1);
        return ans;
    }
    int numTrees(int n) {
        return help(n);
    }
};