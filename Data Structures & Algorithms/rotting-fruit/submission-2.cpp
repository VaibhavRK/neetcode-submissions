class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        int t = 0;
        while(!q.empty()){
            int sz = q.size();
            t++;

            cout<<sz<<" "<<t<<endl;
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                int dr[] = {1,-1,0,0};
                int dc[] = {0,0,1,-1};

                for(int i=0;i<4;i++){
                    int xx = x + dr[i];
                    int yy = y + dc[i];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                    if(vis[xx][yy]) continue;
                    if(grid[xx][yy] == 0 || grid[xx][yy] == 2) continue; 
                    vis[xx][yy] = 1;
                    q.push({xx,yy});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1) return -1;
            }
        }

        if(t == 0) return 0;
        return t-1;
    }
};
