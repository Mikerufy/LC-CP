class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        for(int i=d.size()-1;i>=0;i--){
            d[i] += 1;
            if(d[i] == 10)
                d[i] = 0;
            else
                break;
        }
        if(d[0] == 0)
            d.insert(d.begin(), 1);
        return d;
    }
};