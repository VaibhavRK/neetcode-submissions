class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        vector<pair<int,int>> graph[n];

        for(vector<int> edges : flights){
            int a = edges[0];
            int b = edges[1];
            int wt = edges[2];

            graph[a].push_back({b, wt});
        }

        // FIX 1: Drop the cost array. Track the max 'times' (stops remaining) we had when reaching a node.
        vector<int> max_times(n, -1); 
        
        pq.push({0, {src, k}});

        while(!pq.empty()){
            int curr_cost = pq.top().first;        // We need to extract the cost from the PQ
            int node = pq.top().second.first;
            int times = pq.top().second.second;
            pq.pop();
            
            // FIX 2: Because PQ orders by cost, the first time we pop dst, it is guaranteed to be the cheapest valid path!
            if (node == dst) return curr_cost;
            
            // FIX 3: Pruning conditions
            // 1. times < 0: We ran out of stops (k stops = k+1 edges). 
            // 2. max_times[node] >= times: We've already been to this node with a cheaper cost AND more stops remaining.
            if(times < 0 || max_times[node] >= times) continue;
            
            // Record that we reached this node with this many stops remaining
            max_times[node] = times;

            for(pair<int,int> e : graph[node]){
                int child = e.first;
                int wt = e.second;

                // FIX 4: No cost array comparison needed. Just push the new cost and times-1.
                pq.push({curr_cost + wt, {child, times - 1}});
            }
        }

        return -1; // If we never popped dst, it's unreachable within k stops
    }
};