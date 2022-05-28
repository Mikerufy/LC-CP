class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string c = s;
        reverse(c.begin(),c.end());
        return (c==s);
    }
};