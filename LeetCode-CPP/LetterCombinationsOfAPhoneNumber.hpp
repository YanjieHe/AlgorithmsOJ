#ifndef LETTERCOMBINATIONSOFAPHONENUMBER_HPP
#define LETTERCOMBINATIONSOFAPHONENUMBER_HPP
#include "common_header_files.hpp"
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return vector<string>();
        }
        else
        {
            unordered_map<int, string> map = {
                {2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
                {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
            vector<string> result;
            makeCombinations(digits, 0, vector<char>(), result, map);
            return result;
        }
    }
    void makeCombinations(string& digits, int index, vector<char> characters,
                          vector<string>& result,
                          unordered_map<int, string>& map)
    {
        if (index < static_cast<int>(digits.size()))
        {
            for (auto c : map[digits[index] - '0'])
            {
                characters.push_back(c);
                makeCombinations(digits, index + 1, characters, result, map);
                characters.pop_back();
            }
        }
        else
        {
            auto s = string(characters.begin(), characters.end());
            result.push_back(s);
        }
    }
    static void test()
    {
        Solution solution;
        string digits = "23";
        auto result = solution.letterCombinations(digits);
        for (auto s : result)
        {
            cout << s << endl;
        }
    }
};
#endif // LETTERCOMBINATIONSOFAPHONENUMBER_HPP
