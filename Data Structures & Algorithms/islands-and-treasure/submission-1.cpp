class Solution {
public:
    const int mx = 2147483647;

    int traverse(int x,int y, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(x >= n || y >= m || y < 0 || x < 0) return mx;
        if(grid[x][y] == -1) return mx;
        if(grid[x][y] == 0) return 1;
        if(vis[x][y]){
            if(grid[x][y] != mx) return grid[x][y]+1;
            return mx;
        }
        
        vis[x][y] = 1;
        grid[x][y] = min(grid[x][y], traverse(x+1, y, vis, grid));
        grid[x][y] = min(grid[x][y], traverse(x-1, y, vis, grid));
        grid[x][y] = min(grid[x][y], traverse(x, y+1, vis, grid));
        grid[x][y] = min(grid[x][y], traverse(x, y-1, vis, grid));

        return grid[x][y];
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        // Step 1: Push all treasure chests (0) into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Directions array for moving Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check boundaries and if the neighbor is an empty land cell (INF)
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = grid[r][c] + 1; // Update distance
                    q.push({nr, nc});              // Push neighbor to queue
                }
            }
        }
    }
};
