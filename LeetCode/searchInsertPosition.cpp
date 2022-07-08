/*
 * LeetCode: 35. Searcb Insert Position
 * Time Complexity: O(logn)
 */

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid;
        // Searching if the element is present in an array.
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // If target is not present in an array, then the position where it store.
        if (nums[mid] > target)
            return mid;
        else
            return mid + 1;
    }
};