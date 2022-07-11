class Solution
{
public:
    // Method 1:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows); // create 'n' dynamic vectors

        for (int i = 0; i < numRows; i++)
        {
            // for every row, the number of columns always equal to number of rows
            r[i].resize(i + 1);    // empty vector is resized to a size i+1
            r[i][0] = r[i][i] = 1; // every first and last element is '1'
            // Linearly traverse from 1st column to 2nd last column
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        return r;
    }

    // Method 2:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> arr;
        vector<int> a;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                    a.push_back(1);
                else
                    a.push_back(arr[i - 1][j - 1] + arr[i - 1][j]);
            }
            arr.push_back(a);
            a.clear();
        }
        return arr;
    }
};