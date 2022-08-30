class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == false)
                {
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
    private:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            if(vis[curx][cury] == true)
            {
                continue;
            }
            vis[curx][cury] = true;
            int dr[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
            for(int i=0;i<4;i++)
            {
                int dx = dr[i][0];
                int dy = dr[i][1];
                int nbri = curx+dx;
                int nbrj = cury+dy;
                if(nbri>=0 && nbri<n && nbrj>=0 && nbrj<m && grid[nbri][nbrj] == '1')
                {
                    q.push({nbri,nbrj});
                }
            }
        }
    }
};