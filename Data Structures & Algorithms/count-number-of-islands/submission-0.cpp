class Solution {
public:

    void traverse(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        if(x >= n || x < 0 || y >= m || y < 0) return;
        if(grid[x][y] == '0') return;

        if(vis[x][y]) return;

        vis[x][y] = 1;
        
        
        traverse(x+1,y,grid, vis);
        traverse(x-1,y,grid, vis);
        traverse(x,y+1,grid, vis);
        traverse(x,y-1,grid, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    traverse(i,j,grid,vis);
                }
            }
        }

        return ans;
    }
};
