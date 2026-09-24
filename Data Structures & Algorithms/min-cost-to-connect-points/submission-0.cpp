class Solution {
public:

    int parent[1001];
    int sizes[1001];

    void make(int v){
        parent[v] = v;
        sizes[v] = 1;
    }

    int find(int v){
        if(parent[v] == v) return v;

        parent[v] = find(parent[v]);
        return parent[v];
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);

        if(sizes[a] < sizes[b]){
            int t = a;
            a = b;
            b = t;
        }

        parent[b] = a;
        sizes[a] += sizes[b];
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<pair<int,pair<int,int>>> edges;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dis = abs(x1-x2) + abs(y1-y2);
                edges.push_back({dis,{i,j}});
            }
        }

        for(int i=0;i<n;i++){
            make(i);
        }

        sort(edges.begin(), edges.end());
        int cost = 0;

        for(pair<int,pair<int,int>> p : edges){
            int dis = p.first;
            int a = p.second.first;
            int b = p.second.second;

            if(find(a) != find(b)){
                Union(a,b);
                cost += dis;
            }
        }

        return cost;
    }
};
