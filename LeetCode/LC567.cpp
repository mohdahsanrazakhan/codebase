class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        // creating two hash
        vector<int> s1hash(26, 0);
        vector<int> s2hash(26, 0);

        // calculating both length
        int s1len = s1.size();
        int s2len = s2.size();

        // s2 can't contain any permutation of s1 if length of s2 is less than s1
        if (s1len > s2len)
            return false;

        // calculating the first window
        int left = 0, right = 0;
        while (right < s1len)
        {
            s1hash[s1[right] - 'a'] += 1;
            s2hash[s2[right] - 'a'] += 1;
            right += 1;
        }

        right -= 1; // to piont right to the end of the window

        // Using sliding window technique, and slide one char at a time and keep updating a values
        while (right < s2len)
        {
            if (s1hash == s2hash)
                return true;
            right += 1;
            if (right != s2len)
                s2hash[s2[right] - 'a'] += 1;
            s2hash[s2[left] - 'a'] -= 1;
            left += 1;
        }
        return false;
    }
};