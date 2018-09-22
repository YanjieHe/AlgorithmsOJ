#ifndef BINARYTREELEVELORDERTRAVERSALII_HPP
#define BINARYTREELEVELORDERTRAVERSALII_HPP
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "common_header_files.hpp"
#include <algorithm>
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val{x}
        , left{NULL}
        , right{NULL}
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val{x}
        , left{left}
        , right{right}
    {
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> result;
        traverse(root, result, 0);
        std::reverse(result.begin(), result.end());
        return result;
    }
    void traverse(TreeNode* node, vector<vector<int>>& result, int depth)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            while (depth >= result.size())
            {
                result.push_back(vector<int>());
            }
            result[depth].push_back(node->val);
            traverse(node->left, result, depth + 1);
            traverse(node->right, result, depth + 1);
        }
    }
};
#endif // BINARYTREELEVELORDERTRAVERSALII_HPP
