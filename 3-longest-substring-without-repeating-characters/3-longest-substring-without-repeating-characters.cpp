class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxsofar = 0;
        int count = 0;
        int i = 0;
        unordered_map<char,int> m;
        while(i<s.size())
        {
            if(m.find(s[i])!= m.end())
            {
                count = 0;
                i = m[s[i]] + 1;
                m.clear();
            }
            else
            {
                count++;
                maxsofar = max(maxsofar,count);
                m[s[i]] = i;
                i++;
            }
        }
        return maxsofar;
    }
};