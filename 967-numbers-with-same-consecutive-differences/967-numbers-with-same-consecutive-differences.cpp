class Solution {
public:
    vector<int> ans;
    void help(int n,int k,string num,int idx,int prev){
        if(num.size() == n){
            ans.push_back(stoi(num));return;
        }
        for(int i=0;i<=9;i++){
            if(i==0 and idx == 0)continue;
            if(prev != -1 and abs(prev-i)==k){
                num += to_string(i);
                help(n,k,num,idx+1,i);
                num.pop_back();
            }
            if(prev == -1){
                num += to_string(i);
                help(n,k,num,idx+1,i);
                num.pop_back();
            }
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string num = "";
        help(n,k,num,0,-1);
        return ans;
    }
};