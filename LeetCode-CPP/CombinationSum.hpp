#ifndef COMBINATIONSUM_HPP
#define COMBINATIONSUM_HPP
#include "common_header_files.hpp"
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        makeCombination(candidates, vector<int>(), result, target);
        return result;
    }
    void makeCombination(vector<int>& candidates, vector<int> combination,
                         vector<vector<int>>& result, int target)
    {
        int n = candidates.size();
        for (int i = 0; i < n; i++)
        {
            if (combination.size() != 0 && combination.back() > candidates[i])
            {
                continue;
            }
            else
            {
                int d = target - candidates[i];
                if (d == 0)
                {
                    combination.push_back(candidates[i]);
                    result.push_back(combination);
                    combination.pop_back();
                }
                else if (d > 0)
                {
                    combination.push_back(candidates[i]);
                    makeCombination(candidates, combination, result, d);
                    combination.pop_back();
                }
            }
        }
    }
    static void test()
    {
        Solution solution;
        vector<int> input = {2, 3, 5};
        auto result = solution.combinationSum(input, 8);
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
#endif // COMBINATIONSUM_HPP
