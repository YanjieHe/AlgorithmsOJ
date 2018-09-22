#ifndef COUNTPRIMES_HPP
#define COUNTPRIMES_HPP
#include "common_header_files.hpp"
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i])
            {
                for (int k = i * 2; k <= n; k += i)
                {
                    isPrime[k] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i])
            {
                count++;
            }
        }
        return count;
    }
    static void test()
    {
        Solution solution;
        cout << solution.countPrimes(10) << endl;
    }
};
#endif // COUNTPRIMES_HPP
