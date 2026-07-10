class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1) return false;

        unordered_map<int, vector<int>> neighbours(n);
        for(int i = 0; i < edges.size(); i++) {
            neighbours[edges[i][0]].push_back(edges[i][1]);
            neighbours[edges[i][1]].push_back(edges[i][0]);
        }

        unordered_set<int> visits;

        if(!dfs(0, neighbours, visits, -1)) return false;

        return visits.size() == n;
    }

    bool dfs(int node, unordered_map<int, vector<int>>& neighbours, 
                unordered_set<int>& visits, int parent) {
        if(visits.count(node)) return false;

        visits.insert(node);

        for(auto nei: neighbours[node]) {
            if(nei == parent) continue;

            if(!dfs(nei, neighbours, visits, node)) return false;
        }

        return true;
    }
};
