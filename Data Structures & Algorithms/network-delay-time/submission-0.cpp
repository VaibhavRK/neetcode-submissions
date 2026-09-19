class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);

        for(vector<int> v : times){
            graph[v[0]].push_back({v[1], v[2]});
        }

        queue<pair<int,int>> q;
        q.push({k,0});

        vector<int> vis(n+1, INT_MAX);
        vis[k] = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                int node = q.front().first;
                int currTime = q.front().second;
                q.pop();

                for(pair<int,int> p : graph[node]){
                    if(vis[p.first] > p.second + currTime){
                        vis[p.first] = p.second + currTime;
                        q.push({p.first,p.second+currTime});
                    }
                }
            }
        }

        

        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans, vis[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }   
};
