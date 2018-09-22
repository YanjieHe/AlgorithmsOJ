#ifndef LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_HPP
#define LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_HPP
#include "common_header_files.hpp"
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> dict(256, -1);
        int maxLength = 0;
        int start = -1;
        for (int i = 0, n = s.size(); i < n; i++)
        {
            char c = s[i];
            start = std::max(dict[c], start);
            dict[c] = i;
            maxLength = std::max(maxLength, i - start);
        }
        return maxLength;
    }
    static void test()
    {
        Solution solution;
        cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
        cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
        cout << solution.lengthOfLongestSubstring("pwwkew") << endl;
        cout << solution.lengthOfLongestSubstring("dvdf") << endl;
    }
};
#endif // LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_HPP
