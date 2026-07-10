class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj(n);
        vector<bool> visit(n, false);
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!visit[i]) {
                bfs(i, adj, visit);
                ans++;
            }
        }

        return ans;
    }

    void bfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visit) {
        queue<int> q;
        q.push(i);
        visit[i] = true;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int nei: adj[cur]) {
                if(!visit[nei]) {
                    q.push(nei);
                    visit[nei] = true;
                }
            }
        }
    }
};
