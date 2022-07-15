class Solution {
public:
    int help(vector<vector<int>> &v,int i, int j){
        if(i<0 or j<0 or i>=v.size() or j>= v[0].size())return 0;
        if(v[i][j] == 0)return 0;
        int x[4] = {1,0,0,-1};
        int y[4] = {0,1,-1,0};
        int ans = 1;
        v[i][j] = 0;
        for(int k=0;k<4;k++){
            int a = i + x[k];
            int b = j + y[k];
            if(a>=0 and b>=0 and a<v.size() and b< v[0].size() and v[a][b] == 1){
                ans += help(v,a,b);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])
                    ans = max(ans,help(grid,i,j));
            }
        }
        return ans;
    }
};