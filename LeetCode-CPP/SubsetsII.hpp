#ifndef SUBSETSII_HPP
#define SUBSETSII_HPP
#include "common_header_files.hpp"
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> result;
        unordered_map<int, vector<vector<int>>> map;
        getPowerSet2(nums, result, map);
        return result;
    }
    void getPowerSet2(vector<int>& nums, vector<vector<int>>& result,
                      unordered_map<int, vector<vector<int>>>& map)
    {
        int end = (1 << static_cast<int>(nums.size())) - 1;
        for (int mark = 0; mark <= end; mark++)
        {
            vector<int> vec;
            for (unsigned i = 0; i < nums.size(); i++)
            {
                if (((1 << i) & mark) != 0)
                {
                    vec.push_back(nums[i]);
                }
            }
            std::sort(vec.begin(), vec.end());
            if (!isExist(map, vec))
            {
                result.push_back(vec);
            }
        }
    }
    bool isExist(unordered_map<int, vector<vector<int>>>& map, vector<int>& vec)
    {
        int hash = hashCode(vec);
        if (map.find(hash) != map.end())
        {
            for (auto item : map[hash])
            {
                if (vec == item)
                {
                    return true;
                }
            }
            map[hash].push_back(vec);
            return false;
        }
        else
        {
            map[hash].push_back(vec);
            return false;
        }
    }
    int hashCode(vector<int>& vec)
    {
        int hash = 0;
        if (hash == 0 && !vec.empty())
        {
            for (unsigned i = 0; i < vec.size(); i++)
            {
                hash = 31 * hash + vec[i];
            }
        }
        return hash;
    }
    static void test()
    {
        Solution solution;
        auto nums = vector{4, 4, 4, 1, 4};
        auto result = solution.subsetsWithDup(nums);
        for (auto vec : result)
        {
            if (vec.empty())
            {
                cout << "@" << endl;
            }
            else
            {
                for (auto item : vec)
                {
                    cout << item << " ";
                }
                cout << endl;
            }
        }
    }
};
#endif // SUBSETSII_HPP
