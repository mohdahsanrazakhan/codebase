/*
 * LeetCode: 56. Merge Intervals
 * Time Complexity: O(NlogN) for sorting + O(N) for linearly traversing
 * Space Complexity: O(N) in worst case
 */

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> mergedIntervals;

        // Edge Case: Not give any intervals
        if (intervals.size() == 0)
        {
            return mergedIntervals;
        }

        // If interval given then sort
        sort(intervals.begin(), intervals.end());

        // tempInterval contain the first interval
        vector<int> tempInterval = intervals[0];

        // Traverse through the given interval
        for (auto it : intervals)
        {
            // Checking for merging
            if (it[0] <= tempInterval[1])
            {
                tempInterval[1] = max(it[1], tempInterval[1]); // merging
            }
            else
            {
                mergedIntervals.push_back(tempInterval); // not merging
                tempInterval = it;
            }
        }
        // Push the last interval into mergedIntervals
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};