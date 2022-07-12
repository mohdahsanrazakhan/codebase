class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        /* First Approach: By soring an array
         * TC: O(NlogN) for sorting + O(1) for extra space
         */
        sort(nums.begin(), nums.end());
        int dupNum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (dupNum != nums[i])
                dupNum = nums[i];
            else
                break;
        }
        return dupNum;

        /* Optimized Approach: Using hash table
         * TC: O(N)
         * SC: O(N)
         */

        /* Most Optimized Approach: Using Linked List cycle method (Using tortoise method)
         * TC: O(N)
         * SC: O(1)
         */

        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];       // move one step
            fast = nums[nums[fast]]; // move two step
        } while (slow != fast);

        // if slow and fast are collide, set fast at 0 index
        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow]; // move one step
            fast = nums[fast]; // move one step
        }
        return slow;
    }
};