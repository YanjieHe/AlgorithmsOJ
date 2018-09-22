#ifndef COMBINATIONSUMII_HPP
#define COMBINATIONSUMII_HPP
#include "common_header_files.hpp"
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<bool> used(candidates.size(), false);
        makeCombinations(candidates, used, vector<int>(), result, target);
        return result;
    }
    void makeCombinations(vector<int>& candidates, vector<bool>& used,
                          vector<int> combination, vector<vector<int>>& result,
                          int target)
    {
        for (int i = 0, n = candidates.size(); i < n; i++)
        {
            if (!used[i])
            {
                if (combination.size() != 0 &&
                    candidates[i] < combination.back())
                {
                    continue;
                }
                else
                {
                    int d = target - candidates[i];
                    if (d == 0)
                    {
                        combination.push_back(candidates[i]);
                        appendIfNotExists(result, combination);
                        combination.pop_back();
                    }
                    else if (d > 0)
                    {
                        combination.push_back(candidates[i]);
                        used[i] = true;
                        makeCombinations(candidates, used, combination, result,
                                         d);
                        combination.pop_back();
                        used[i] = false;
                    }
                }
            }
        }
    }
    void appendIfNotExists(vector<vector<int>>& result, vector<int> combination)
    {
        for (auto v : result)
        {
            if (v == combination)
            {
                return;
            }
        }
        result.push_back(combination);
    }
    static void test()
    {
        Solution solution;
        vector<int> input = {10, 1, 2, 7, 6, 1, 5};
        auto result = solution.combinationSum2(input, 8);
        for (auto v : result)
        {
            for (auto item : v)
            {
                cout << item << " ";
            }
            cout << endl;
        }
    }
};
#endif // COMBINATIONSUMII_HPP
