/*
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 */

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size(); // size of the number of columns

        // Transpose the matrix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);

        // Reverse the matrix
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};