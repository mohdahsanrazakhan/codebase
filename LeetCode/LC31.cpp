/*
 * LeetCode: 31. Next Permutation
 * TC: O(N)
 * SC: O(1)
 */
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), k, l;
        // Linearly traverse to the second last element and try to find break point
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }

        // If no break point then reverse remaining elements
        if (k < 0)
            reverse(nums.begin(), nums.end());
        else
        { // If there is a break point then again linearly traverse from the last
            for (l = n - 1; l > k; l--)
            {
                if (nums[l] > nums[k])
                {
                    break;
                }
            }
            swap(nums[k], nums[l]);                    // also write own code for swap
            reverse(nums.begin() + k + 1, nums.end()); // also write own code for reverse
        }
    }
};