int func(vector<vector<int>>& grid, int i, int j, int n, int m,vector<vector<int>>&visited) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j]==1) {
            return 0;  // Base case: out of bounds or already visited
        }
        int original_val = grid[i][j];
        visited[i][j]=1;

        // Explore all directions
        int left = func(grid, i, j - 1, n, m,visited);
        int right = func(grid, i, j + 1, n, m,visited);
        int up = func(grid, i - 1, j, n, m,visited);
        int down = func(grid, i + 1, j, n, m,visited);

        return original_val + left + right + up + down;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        // Try starting at each cell with a positive value
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0) {
                    vector<vector<int>>visited(n,vector<int>(m,-1));
                    ans = max(ans, func(grid, i, j, n, m,visited));
                }
            }
        }

        return ans;
    }
