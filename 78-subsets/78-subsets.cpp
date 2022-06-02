class Solution {
public:
    vector<vector<int>> v;
    vector<int> c;
    void help(vector<int> &n,int i){
        if(i>=n.size()){
            v.push_back(c);
            return;
        }
        c.push_back(n[i]);
        help(n,i+1);
        c.pop_back();
        help(n,i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        help(nums,0);
        return v;
    }
};