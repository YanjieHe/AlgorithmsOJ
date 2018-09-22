#ifndef INTEGERTOROMAN_HPP
#define INTEGERTOROMAN_HPP
#include "common_header_files.hpp"
class Solution
{
public:
    int romanNumerals(char c)
    {
        switch (c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                throw string("incorrect argument format");
        }
    }
    string intToRoman(int num)
    {
        vector<char> builder;
        writeThoudands(num, builder);
        writeHundreds(num, builder);
        writeTens(num, builder);
        writeDigits(num, builder);
        return string(builder.begin(), builder.end());
    }
    void writeThoudands(int num, vector<char>& builder)
    {
        int thousands = num / 1000;
        if (thousands > 0)
        {
            for (int i = 0; i < thousands; i++)
            {
                builder.push_back('M');
            }
        }
    }
    void writeHundreds(int num, vector<char>& builder)
    {
        int thousands = num / 1000;
        num = num - thousands * 1000;
        int hundreds = num / 100;
        if (hundreds > 0)
        {
            if (hundreds == 4)
            {
                builder.push_back('C');
                builder.push_back('D');
            }
            else if (hundreds == 9)
            {
                builder.push_back('C');
                builder.push_back('M');
            }
            else if (hundreds >= 5)
            {
                builder.push_back('D');
                for (int i = 0; i < hundreds - 5; i++)
                {
                    builder.push_back('C');
                }
            }
            else
            {
                for (int i = 0; i < hundreds; i++)
                {
                    builder.push_back('C');
                }
            }
        }
    }
    void writeTens(int num, vector<char>& builder)
    {
        int hundreds = num / 100;
        num = num - hundreds * 100;
        int tens = num / 10;
        if (tens > 0)
        {
            if (tens == 9)
            {
                builder.push_back('X');
                builder.push_back('C');
            }
            else if (tens == 4)
            {
                builder.push_back('X');
                builder.push_back('L');
            }
            else if (tens >= 5)
            {
                builder.push_back('L');
                for (int i = 0; i < tens - 5; i++)
                {
                    builder.push_back('X');
                }
            }
            else
            {
                for (int i = 0; i < tens; i++)
                {
                    builder.push_back('X');
                }
            }
        }
    }
    void writeDigits(int num, vector<char>& builder)
    {
        int tens = num / 10;
        num = num - tens * 10;
        int digits = num;
        if (digits > 0)
        {
            if (digits == 9)
            {
                builder.push_back('I');
                builder.push_back('X');
            }
            else if (digits == 4)
            {
                builder.push_back('I');
                builder.push_back('V');
            }
            else if (digits >= 5)
            {
                builder.push_back('V');
                for (int i = 0; i < digits - 5; i++)
                {
                    builder.push_back('I');
                }
            }
            else
            {
                for (int i = 0; i < digits; i++)
                {
                    builder.push_back('I');
                }
            }
        }
    }
    static void test()
    {
        Solution solution;
        cout << solution.intToRoman(3) << endl;
        cout << solution.intToRoman(4) << endl;
        cout << solution.intToRoman(9) << endl;
        cout << solution.intToRoman(58) << endl;
        cout << solution.intToRoman(1994) << endl;
    }
};
#endif // INTEGERTOROMAN_HPP
