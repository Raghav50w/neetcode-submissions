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
                queue<int> q;
                q.push(i);

                while(!q.empty()) {
                    int curr = q.front();
                    visit[curr] = true;
                    q.pop();

                    for(int nei: adj[curr]) {
                        if(!visit[nei]) q.push(nei);
                    }
                }

                ans++;
            }
        }

        return ans;
    }
};
