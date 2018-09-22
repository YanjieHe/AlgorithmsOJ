#ifndef MAXIMALRECTANGLE_HPP
#define MAXIMALRECTANGLE_HPP
#include "common_header_files.hpp"
#include <cmath>
class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }
        else
        {
            int nRows = matrix.size();
            int nCols = matrix.at(0).size();
            vector<int> L(nCols, 0);
            vector<int> R(nCols, nCols);
            vector<int> H(nCols, 0);

            int maxArea = 0;
            for (int row = 0; row < nRows; row++)
            {
                int left = 0;
                int right = 0;
                for (int col = 0; col < nCols; col++)
                {
                    if (matrix[row][col] == '1')
                    {
                        H[col]++;
                        L[col] = std::max(L[col], left);
                    }
                    else
                    {
                        H[col] = 0;
                        L[col] = 0;
                        left = col + 1;
                    }
                }
                for (int col = nCols - 1; col >= 0; col--)
                {
                    if (matrix[row][col] == '1')
                    {
                        R[col] = std::min(L[col], right);
                    }
                    else
                    {
                        R[col] = nCols;
                        right = col;
                    }
                }
                for (int col = 0; col < nCols; col++)
                {
                    maxArea = std::max(maxArea, (R[col] - L[col]) * H[col]);
                }
            }
            return maxArea;
        }
    }
    int countOnes(vector<vector<char>>& matrix, int startRow, int endRow,
                  int startCol, int endCol)
    {
        if (startRow > endRow)
        {
            return countOnes(matrix, endRow, startRow, startCol, endCol);
        }
        else if (startCol > endCol)
        {
            return countOnes(matrix, startRow, endRow, endCol, startCol);
        }
        else
        {
            int count = 0;
            for (int row = startRow; row <= endRow; row++)
            {
                for (int col = startCol; col <= endCol; col++)
                {
                    if (matrix[row][col] == '1')
                    {
                        count++;
                    }
                    else
                    {
                        return (-1);
                    }
                }
            }
            return count;
        }
    }
    static void test()
    {
        vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                       {'1', '0', '1', '1', '1'},
                                       {'1', '1', '1', '1', '1'},
                                       {'1', '0', '0', '1', '0'}};
        Solution solution;
        cout << solution.maximalRectangle(matrix) << endl;
    }
};
#endif // MAXIMALRECTANGLE_HPP
