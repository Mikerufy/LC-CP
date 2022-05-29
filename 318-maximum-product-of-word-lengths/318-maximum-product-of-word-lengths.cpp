class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> mask(n,0);
        for(int i=0;i<words.size();i++){
            int x=0;
            for(int j=0;j<words[i].size();j++){
                x |= (1<<(words[i][j]-'a'));
            }
            mask[i] = x;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask[i]&mask[j])==0){
                    ans = max(ans,(int)(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};