class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        set<string> st,vis;
        for(auto&i:bank)st.insert(i);
        q.push(start);
        vis.insert(start);
        char arr[4] = {'A','C','G','T'};
        int cnt = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto tmp = q.front();
                q.pop();
                if(tmp == end)return cnt;
                for(int i=0;i<8;i++){
                    char prev = tmp[i];
                    for(int j=0;j<4;j++){
                        tmp[i] = arr[j];
                        if(st.count(tmp)>0 and !vis.count(tmp)){
                            q.push(tmp); 
                            vis.insert(tmp);
                        }
                    }
                    tmp[i] = prev;
                }
            }
            cnt++;
        }
        return -1;
    }
};