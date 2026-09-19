class Solution {
public:
    void dfs(int node, map<int, multiset<int>>& graph, vector<int> &ans){
        while(!graph[node].empty()){
            // Get the iterator to the first available ticket
            auto it = graph[node].begin();
            int child = *it;
            
            // Erase ONLY ONE instance of the ticket using the iterator
            graph[node].erase(it);
            dfs(child, graph, ans);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        set<string> st;
        for(vector<string> v : tickets){
            st.insert(v[0]);
            st.insert(v[1]);
        }

        unordered_map<string, int> mp;
        unordered_map<int, string> mp1;
        int ct = 0;
        for(string node : st){
            mp1[ct] = node;
            mp[node] = ct;
            ct++;
        }

        // Use multiset to support duplicate tickets
        map<int, multiset<int>> graph;
        for(int i = 0; i < tickets.size(); i++){
            int u = mp[tickets[i][0]];
            int v = mp[tickets[i][1]]; 
            graph[u].insert(v);
        }

        vector<int> ans;
        dfs(mp["JFK"], graph, ans);

        vector<string> res;
        for(int num : ans){
            res.push_back(mp1[num]);
        }    
        reverse(res.begin(), res.end());    
        return res;
    }
};