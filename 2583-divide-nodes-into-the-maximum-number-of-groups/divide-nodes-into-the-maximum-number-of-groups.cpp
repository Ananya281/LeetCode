class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1); // -1: unvisited, 0: first color, 1: second color
        vector<int> component(n + 1, -1); // To track components
        int comp_id = 0;
        unordered_map<int, vector<int>> components;
        
        // Checking bipartiteness & grouping components
        function<bool(int)> isBipartite = [&](int start) {
            queue<int> q;
            q.push(start);
            color[start] = 0;
            component[start] = comp_id;
            components[comp_id].push_back(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        component[neighbor] = comp_id;
                        components[comp_id].push_back(neighbor);
                        q.push(neighbor);
                    } 
                    else if (color[neighbor] == color[node]) {
                        return false; // Odd cycle detected
                    }
                }
            }
            return true;
        };

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                components[comp_id] = {};
                if (!isBipartite(i)) return -1;
                comp_id++;
            }
        }

        // Function to determine maximum depth from a node using BFS
        auto maxBFSDepth = [&](int start) {
            queue<int> q;
            unordered_map<int, int> depth;
            q.push(start);
            depth[start] = 1;
            int maxDepth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (depth.find(neighbor) == depth.end()) {
                        depth[neighbor] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth;
        };

        // Compute the max BFS depth for each component
        int result = 0;
        for (auto& [id, nodes] : components) {
            int maxDepth = 0;
            for (int node : nodes) {
                maxDepth = max(maxDepth, maxBFSDepth(node));
            }
            result += maxDepth;
        }

        return result;
    }
};
