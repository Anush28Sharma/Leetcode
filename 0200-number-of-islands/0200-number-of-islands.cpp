class Solution {
public:

    void bfs(int i,int j,vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
          int m = grid.size();
        int n = grid[0].size();
        vis[i][j] =1;
        queue<pair<int,int>>q;
        q.push({i,j});

        int dr[] ={0,1,0,-1};
        int dc[] = {-1,0,1,0};

        while(!q.empty())
        {
            int row = q.front().first;
            int col  = q.front().second;
            q.pop();

            for(int k = 0;k<4;k++)
            {
                int nrow = row+dr[k];
                int ncol = col+dc[k];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1')
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        int count =0;
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
        
    
    }
};