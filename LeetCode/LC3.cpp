/*
 * TC: O(N)
 * SC: O(N)
 */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mpp(256, -1); // frequency map

        int left = 0, right = 0;
        int n = s.size();
        int len = 0;

        // iterate till last index
        while (right < n)
        {
            // if charater at right index is exist or not
            if (mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left); // exist do mpp[s[right]] + 1, not exist left

            mpp[s[right]] = right; // update the current index in last seen the hash map

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};