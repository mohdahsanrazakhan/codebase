/*
 * LeetCode: 278. First Bad Version
 * TC: O(logn)
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// Way 1: Using binary search
class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n, mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (isBadVersion(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

// Way 2: Using binary search
class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid + 1
        }
        return left;
    }
};
