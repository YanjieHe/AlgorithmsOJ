#ifndef GRAYCODE_HPP
#define GRAYCODE_HPP
#include "common_header_files.hpp"
#include <bitset>
using std::bitset;
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        bitset<32> bits;
        vector<int> result;
        backTrack(bits, result, n);
        return result;
    }
    void backTrack(bitset<32>& bits, vector<int>& result, int k)
    {
        if (k == 0)
        {
            result.push_back(bits.to_ulong());
        }
        else
        {
            backTrack(bits, result, k - 1);
            bits.flip(k - 1);
            backTrack(bits, result, k - 1);
        }
    }
    static void test()
    {
        Solution solution;
        auto result = solution.grayCode(3);
        for (auto item : result)
        {
            cout << item << endl;
        }
    }
};

#endif // GRAYCODE_HPP
