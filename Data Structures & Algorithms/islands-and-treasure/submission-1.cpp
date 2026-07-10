class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        int level = 0;
        while(!q.empty()) {
            int x = q.size();
            for(int i = 0; i < x; i++) {
                auto [r, c] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++) {
                    int nr = r + dir[j][0];
                    int nc = c + dir[j][1];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 2147483647 ) {
                            grid[nr][nc] = grid[r][c] + 1;
                            q.push({nr, nc});
                    }
                }
            }
        }
    };
};
