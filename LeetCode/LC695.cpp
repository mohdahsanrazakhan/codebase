// Using DFS

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        // Stores the area of largest consecutive 1's
        int maxi = 0;

        int m = grid.size(), i;
        int n = grid[0].size(), j;

        // visit each cell of the matrix
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                // begin your traversal from the cell which has value as 1(lend)
                if (grid[i][j] == 1)
                {
                    // store the largest ares
                    maxi = max(maxi, dfs(grid, i, j));
                }
            }
        }
        return maxi;
    }

    // Function to perform DFS in four directinos (up-right-down-left)
    int dfs(vector<vector<int>> &grid, int row, int col)
    {

        int m = grid.size();
        int n = grid[0].size();

        // since the current cell has value = 1 minimum area we start with is 1
        int area = 1;

        // since you have already visited the current cell mark it as already visited
        grid[row][col] = 0;

        // Used for traversing in four directions(up-right-down-left)
        vector<int> dir({-1, 0, 1, 0, -1});

        // we begin our traversal into four directions from the currnet cell
        for (int i = 0; i < 4; i++)
        {
            int r = row + dir[i];
            int c = col + dir[i + 1];

            // make traversals only when next cell lies within the matrix and is unvisited
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                area += dfs(grid, r, c);
        }

        // total number of cells with value 1 visited from the current call
        return area;
    }
};