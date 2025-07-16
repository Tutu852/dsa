class Solution {
  public:
    // Solve function: Check cycle in one component using BFS //from gfg

    bool solve(int src, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
        queue<int> q;
        unordered_map<int, int> parent;
        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            // saare neighbours check karo
            for (auto nbr : adj[frontNode]) {
                if(nbr == parent[frontNode]){
                    continue;
                }
                if (!visited[nbr]) {
                    // agar neighbour visited nahi hai to queue me daalo
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                // agar pehle se visited hai
                // jo node visit kar raha hai kya ye uska parent hai
                // agar parent ke alawa koi aur hai then cycle present hai
                else if (visited[nbr] == true ) {
                    // cycle present
                    return true;
                }
            }
        }
        // cycle not present
        return false;
    }

    // isCycle function: check for cycle in the entire graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;

        // Step 1: Convert edge list to adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // undirected graph hai isliye dono side add kar rahe hain
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        // Step 2: har node ke liye check karo agar visited nahi hai to
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // agar visited nahi hai to check karo agar cycle present hai
                // then aage check karna zaruri nahi hai to true return karo
                bool ans = solve(i, visited, adj);
                if (ans == true) {
                    return true;
                }
            }
        }
        // agar kahi bhi cycle nahi mila to false return karo
        return false;
    }
};
