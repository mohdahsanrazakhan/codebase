/*
 * Roman to Integer
 * Time Complexity: O(n)
 */

class Solution
{
public:
    int romanToInt(string s)
    {
        // Using unordered map
        unordered_map<char, int> romNum{{'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}};

        int intNum = 0, i;
        for (i = 0; i < s.length() - 1; i++)
        {
            cout << romNum[s[i]] << " " << romNum[s[i + 1]] << endl;
            if (romNum[s[i]] < romNum[s[i + 1]])
                intNum -= romNum[s[i]];
            else
                intNum += romNum[s[i]];
        }
        intNum += romNum[s.back()];
        return intNum;
    }
};