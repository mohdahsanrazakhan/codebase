/*
 * LeetCode: 977. Squares of a Sorted Array
 * TC: O(nlogn)
 */

class Solution
{
public:
    // All approach...
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sqr;
        int sqrNum;
        for (int i = 0; i < n; i++)
        {
            sqrNum = nums[i] * nums[i];
            sqr.push_back(sqrNum);
        }
        sort(sqr.begin(), sqr.end());
        return sqr;
    }
};