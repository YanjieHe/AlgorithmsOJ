#ifndef LONGESTPALINDROMICSUBSTRING_HPP
#define LONGESTPALINDROMICSUBSTRING_HPP
#include "common_header_files.hpp"
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
        {
            return s;
        }
        else
        {
            int maxLength = 1;
            int maxLow = 0;
            int n = s.size();
            for (int i = 0; i < n - 1; i++)
            {
                int low = i;
                int high = i + 1;
                int length = 0;
                while (low >= 0 && high < n)
                {
                    if (s[low] == s[high])
                    {
                        low--;
                        high++;
                        length += 2;
                    }
                    else
                    {
                        break;
                    }
                }
                if (maxLength < length)
                {
                    maxLow = low + 1;
                    maxLength = length;
                }
            }
            for (int i = 1; i < n - 1; i++)
            {
                int low = i - 1;
                int high = i + 1;
                int length = 1;
                while (low >= 0 && high < n)
                {
                    if (s[low] == s[high])
                    {
                        low--;
                        high++;
                        length += 2;
                    }
                    else
                    {
                        break;
                    }
                }
                if (maxLength < length)
                {
                    maxLow = low + 1;
                    maxLength = length;
                }
            }
            return s.substr(maxLow, maxLength);
        }
    }
    bool isPalindrome(string& s, int low, int high)
    {
        while (low < high)
        {
            if (s[low] != s[high])
            {
                return false;
            }
            else
            {
                low++;
                high--;
            }
        }
        return true;
    }
    static void test()
    {
        Solution solution;
        cout << solution.longestPalindrome("babad") << endl;
        cout << solution.longestPalindrome("cbbd") << endl;
    }
};
#endif // LONGESTPALINDROMICSUBSTRING_HPP
