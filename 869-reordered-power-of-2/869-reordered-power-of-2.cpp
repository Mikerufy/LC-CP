class Solution {
public:
    vector<int> help(int n){
        vector<int> ans(10,0);
        while(n>0){
            ans[n%10]++;
            n/=10;
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> freq = help(n);
        
        for(int i=0;i<31;i++){
            vector<int> tmp = help(1<<i);
            bool yes = true;
            for(int j=0;j<10;j++){
                if(tmp[j] != freq[j])yes = false;
            }
            if(yes)return true;
        }
        return false;
    }
};