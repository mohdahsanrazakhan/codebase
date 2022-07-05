/*
 * Longest Common Prefix
 * Time Complexity: O(n)
 */

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int strlen = strs.size();
        // Empty string
        if (strlen == 0)
            return "";

        string equalStr = "";
        // By sorting, first and last string may or may not same.
        sort(strs.begin(), strs.end());
        string str1 = strs[0];          // store first string
        string str2 = strs[strlen - 1]; // store last string

        cout << str1 << endl;
        cout << str2 << endl;
        // Comparing common characters of two strings
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] == str2[i])
                equalStr += str1[i];
            else
                break;
        }
        return equalStr;
    }
};