class Solution {
public:
    // Returns true if a cycle is detected, false otherwise.
    bool topoSort(int node, stack<int>& st, vector<int> graph[], vector<int>& vis) {
        vis[node] = 1; // Mark as "currently visiting" (in current DFS path)

        for(int child : graph[node]) {
            if (vis[child] == 1) return true; // Cycle detected!
            if (vis[child] == 0) {
                if (topoSort(child, st, graph, vis)) return true;
            }
        }

        vis[node] = 2; // Mark as "fully visited"
        st.push(node);
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<int> graph[26];
        
        // Track which characters actually exist in the given words
        vector<bool> present(26, false);
        for (const string& word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Build the graph
        for(int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];

            // Edge case: s1 is longer than s2, and s1 starts with s2 (Invalid dictionary)
            if(s1.length() > s2.length() && s1.substr(0, s2.length()) == s2) {
                return "";
            }

            int len = min(s1.length(), s2.length());
            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    graph[s1[j]-'a'].push_back(s2[j]-'a');
                    break; // CRITICAL: Stop after the first difference!
                }
            }
        }

        stack<int> st;
        // vis array states: 0 = unvisited, 1 = visiting (in path), 2 = visited
        vector<int> vis(26, 0);

        // Run topoSort for ALL characters that are present in the dictionary
        for(int i = 0; i < 26; i++) {
            if(present[i] && vis[i] == 0) {
                // If a cycle is detected during DFS, it's an invalid dictionary
                if (topoSort(i, st, graph, vis)) {
                    return ""; 
                }
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans.push_back('a' + st.top());
            st.pop();
        }

        return ans;
    }
};