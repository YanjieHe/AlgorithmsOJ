#ifndef THREESUM_HPP
#define THREESUM_HPP
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using std::binary_search;
using std::cout;
using std::endl;
using std::ifstream;
using std::sort;
using std::string;
using std::tuple;
using std::unordered_map;
using std::vector;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        unordered_map<int, int> map;
        for (auto item : nums)
        {
            if (map.find(item) != map.end())
            {
                map[item]++;
            }
            else
            {
                map.insert({item, 1});
            }
        }
        vector<vector<int>> result;
        if (nums.size() < 3)
        {
            return result;
        }
        else
        {
            sort(nums.begin(), nums.end());
            int index = findNonNegativeNumber(nums);
            if (index == -1)
            {
                return result;
            }
            else
            {
                for (int i = 0; i < index; i++)
                {
                    int firstNum = nums.at(i);
                    for (int j = index; j < nums.size(); j++)
                    {
                        int secondNum = nums.at(j);
                        int thirdNum = 0 - firstNum - secondNum;
                        if (thirdNum < 0)
                        {
                            if (thirdNum != firstNum)
                            {
                                if (map.find(thirdNum) != map.end())
                                {
                                    if (thirdNum < firstNum)
                                    {
                                        result.push_back(
                                            {thirdNum, firstNum, secondNum});
                                    }
                                    else
                                    {
                                        result.push_back(
                                            {firstNum, thirdNum, secondNum});
                                    }
                                }
                            }
                            else
                            {
                                if (map[thirdNum] > 1)
                                {
                                    result.push_back(
                                        {firstNum, thirdNum, secondNum});
                                }
                            }
                        }
                        else
                        {
                            if (thirdNum != secondNum)
                            {
                                if (map.find(thirdNum) != map.end())
                                {
                                    if (thirdNum < secondNum)
                                    {
                                        result.push_back(
                                            {firstNum, thirdNum, secondNum});
                                    }
                                    else
                                    {
                                        result.push_back(
                                            {firstNum, secondNum, thirdNum});
                                    }
                                }
                            }
                            else
                            {
                                if (map[thirdNum] > 1)
                                {
                                    result.push_back(
                                        {firstNum, secondNum, thirdNum});
                                }
                            }
                        }
                    }
                }
            }
            if (map.find(0) != map.end())
            {
                if (map[0] >= 3)
                {
                    result.push_back({0, 0, 0});
                }
            }
            return removeDuplicates(result);
        }
    }
    typedef std::tuple<int, int, int> key_t;

    struct key_hash : public std::unary_function<key_t, std::size_t>
    {
        std::size_t operator()(const key_t& k) const
        {
            return std::get<0>(k) ^ std::get<1>(k) ^ std::get<2>(k);
        }
    };

    struct key_equal : public std::binary_function<key_t, key_t, bool>
    {
        bool operator()(const key_t& v0, const key_t& v1) const
        {
            return (std::get<0>(v0) == std::get<0>(v1) &&
                    std::get<1>(v0) == std::get<1>(v1) &&
                    std::get<2>(v0) == std::get<2>(v1));
        }
    };
    bool contains(vector<vector<int>>& result, vector<int>& input)
    {
        for (auto v : result)
        {
            if (v[0] == input[0] && v[1] == input[1] && v[2] == input[2])
            {
                return true;
            }
        }
        return false;
    }
    int findNonNegativeNumber(vector<int>& nums)
    {
        for (int i = 0, n = nums.size(); i < n; i++)
        {
            if (nums[i] >= 0)
            {
                return i;
            }
        }
        return (-1);
    }
    vector<vector<int>> removeDuplicates(vector<vector<int>>& result)
    {
        typedef std::unordered_map<const key_t, vector<int>, key_hash,
                                   key_equal>
            map_t;
        map_t map;
        for (auto v : result)
        {
            map.insert({{v[0], v[1], v[2]}, v});
        }
        vector<vector<int>> output;
        for (auto pair : map)
        {
            output.push_back(pair.second);
        }
        return output;
    }
    static void printResult(vector<vector<int>>& result)
    {
        for (auto v : result)
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    static void printVector(vector<int>& vec)
    {
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    static vector<int> readFromFile(string path)
    {
        ifstream stream(path);
        vector<int> input;
        int v;
        stream >> v;
        while (!stream.eof())
        {
            input.push_back(v);
            stream >> v;
        }
        return input;
    }
    static void basicTest()
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        Solution solution;
        auto result = solution.threeSum(nums);
        printResult(result);
    }
    static void zeroTest()
    {
        vector<int> nums = {0, 0, 0};
        Solution solution;
        auto result = solution.threeSum(nums);
        printResult(result);
    }
    static void test()
    {
        //        basicTest();
        auto nums = readFromFile("3sum.txt");
        Solution solution;
        auto result = solution.threeSum(nums);
        printResult(result);
    }
};

#endif // THREESUM_HPP
