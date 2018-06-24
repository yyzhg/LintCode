class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // write your code here
        int count[52] = {0};
        int oddCount = 0;
        int result = 0;
        
        countString(s, count);
        std::sort(count, count+52);
        for (int i = 0; i < 52; i++)
        {
            std::cout<<count[i]<<",";
        }
        for (int i = 51; i >= 0; --i)
        {
            if (count[i] % 2 == 1)
            {   
                if (oddCount == 0)
                {
                    oddCount = count[i];
                }
                else
                {
                    result += count[i] - 1;
                }
            }
            else if(count[i] % 2 == 0)
            {
                result += count[i];
            }
        }
        return result + oddCount;
        
    }
    
private:
    void countString(string const & s, int (&count)[52])
    {
        int strSize = s.length();
        for (int i = 0; i < strSize; ++i)
        {
            if (islower(s[i]))
            {
                count[s[i] - 'a']++;
            }
            else
            {
                count[s[i] - 'A' + 26]++;
            }
        }
    }

};