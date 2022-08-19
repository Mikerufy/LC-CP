class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq,hyp;
        for(auto& i:nums) freq[i]++;
        for(auto& i:nums){
            if(!freq[i]) continue;
            freq[i]--;
            if(hyp[i]){
                hyp[i]--;
                hyp[i+1]++;
            }else if(freq[i+1] && freq[i+2]){
                freq[i+1]--;
                freq[i+2]--;
                hyp[i+3]++;
            }else return false;
        }
        return true;
    }
};