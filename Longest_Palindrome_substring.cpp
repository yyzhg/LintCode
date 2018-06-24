class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        int length = 0;
        int strLen = s.length();
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < strLen; ++i)
        {
            int lenOfPalindrome = findPalindrome(s, i, i);
            if (lenOfPalindrome > length)
            {
                end = lenOfPalindrome;
                start = i - lenOfPalindrome / 2;
                length = lenOfPalindrome;
            }
            
            lenOfPalindrome = findPalindrome(s, i, i+1);
            if (lenOfPalindrome > length)
            {
                end = lenOfPalindrome;
                start = i - lenOfPalindrome / 2 + 1;
                length = lenOfPalindrome;
            }
        }
        
        return s.substr(start, end);
    }
    
private:
    int findPalindrome(string & s, int start, int end)
    {
        int strLen = s.length();
        while (end < strLen&& start >=0)
        {
            if(s[start] != s[end])
            {
                break;
            }
            end++;
            start--;
        }
        return end - start - 1;
    }
};