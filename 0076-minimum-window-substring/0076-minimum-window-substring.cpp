class Solution {
public:
    bool check(map<char,int>&freq1, map<char,int>&req)
    {
        for(char c='a';c<='z';c++)
        {
            if(req[c]>freq1[c])return false;
        }
        for(char c='A';c<='Z';c++)
        {
            if(req[c]>freq1[c])return false;
        }
        return true;
    }
    string isPossible(map<char,int>&req,int len,string &s)
    {
        bool possible = false;
        map<char,int>freq1;
        deque<char>dq;
        for(int i=0;i<len;i++)
        {
            dq.push_back(s[i]);
            freq1[s[i]]++;
        }
        
        if(check(freq1,req))
        {
            string ans = "";
            for(auto&x:dq)
                ans+=x;
            return ans;
        }
        
        for(int i=len;i<s.size();i++)
        {
            dq.pop_front();
            dq.push_back(s[i]);
            freq1[s[i]]++;
            freq1[s[i-len]]--;
            if(check(freq1,req))
            {
                string ans = "";
                for(auto&x:dq)
                    ans+=x;
                return ans;
            }
        }
        return "";
    }
    string minWindow(string s, string t) {
        
        string ans = "";
        map<char,int>req;
        for(auto&x:t)
            req[x]++;
        
        int l = 1, r = s.size();
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            string curr = isPossible(req,mid,s);
            if(curr!="")
            {
                ans = curr;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return ans;
    }
};