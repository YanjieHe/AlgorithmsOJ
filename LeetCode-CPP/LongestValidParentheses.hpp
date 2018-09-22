#ifndef LONGESTVALIDPARENTHESES_HPP
#define LONGESTVALIDPARENTHESES_HPP
#include "common_header_files.hpp"
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() <= 1)
        {
            return 0;
        }
        else
        {
            int n = s.size();
            int maxLength = 0;
            vector<int> dp(n, 0);
            for (int i = 1; i < n; i++)
            {
                if (s[i] == '(')
                {
                    dp[i] = 0;
                }
                else if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                }
                maxLength = std::max(dp[i], maxLength);
            }
            return maxLength;
        }
    }
    static void test()
    {
        Solution solution;
        cout << solution.longestValidParentheses("(()") << endl;
        cout << solution.longestValidParentheses(")()())") << endl;
    }
};
#endif // LONGESTVALIDPARENTHESES_HPP
