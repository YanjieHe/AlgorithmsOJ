#ifndef VALIDSUDOKU_HPP
#define VALIDSUDOKU_HPP
#include "common_header_files.hpp"
#include <array>

const int N = 9;

template <int row, int col>
class SudokuValidator
{
public:
    static bool valid(vector<vector<char>>& board,
                      std::array<std::array<bool, N>, N>& rowContainers,
                      std::array<std::array<bool, N>, N>& columnContainers,
                      std::array<std::array<bool, N>, N>& boxes)
    {
        char c = board[row][col];
        if (c != '.')
        {
            int number = (c - '0') - 1;
            int boxIndex = (row / 3) * 3 + col / 3;
            if (rowContainers[row][number] || columnContainers[col][number] ||
                boxes[boxIndex][number])
            {
                return false;
            }
            else
            {
                rowContainers[row][number] = true;
                columnContainers[col][number] = true;
                boxes[boxIndex][number] = true;
            }
        }
        return SudokuValidator<row, col + 1>::valid(board, rowContainers,
                                                    columnContainers, boxes);
    }
};

template <int row>
class SudokuValidator<row, N>
{
public:
    static bool valid(vector<vector<char>>& board,
                      std::array<std::array<bool, N>, N>& rowContainers,
                      std::array<std::array<bool, N>, N>& columnContainers,
                      std::array<std::array<bool, N>, N>& boxes)
    {
        return SudokuValidator<row + 1, 0>::valid(board, rowContainers,
                                                  columnContainers, boxes);
    }
};

template <>
class SudokuValidator<N, 0>
{
public:
    static bool valid(vector<vector<char>>& board,
                      std::array<std::array<bool, N>, N>& rowContainers,
                      std::array<std::array<bool, N>, N>& columnContainers,
                      std::array<std::array<bool, N>, N>& boxes)
    {
        return true;
    }
};

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        std::array<std::array<bool, N>, N> rowContainers = {{false}};
        std::array<std::array<bool, N>, N> columnContainers = {{false}};
        std::array<std::array<bool, N>, N> boxes = {{false}};

        return SudokuValidator<0, 0>::valid(board, rowContainers,
                                            columnContainers, boxes);
    }
    static void test()
    {
        vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        Solution solution;
        cout << solution.isValidSudoku(board) << endl;
    }
};
#endif // VALIDSUDOKU_HPP
