class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        vector<int> a(2,0);
        for(int i=0;i<n.size();i++){
            int x = lower_bound(n.begin()+i+1,n.end(),t-n[i]) - n.begin();
            if(x == n.size())continue;
            if(n[x] == t-n[i]){
                a[0] = i+1;
                a[1] = x+1;
                return a;
            }
        }
        return a;
    }
};