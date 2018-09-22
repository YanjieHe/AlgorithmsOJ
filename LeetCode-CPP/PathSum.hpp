#ifndef PATHSUM_HPP
#define PATHSUM_HPP
#include "TreeNode.hpp"
#include "common_header_files.hpp"
class Solution
{
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }
        else
        {
            return traverse(root, 0, sum);
        }
    }
    bool isLeaf(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
    bool traverse(TreeNode* node, int currentSum, int target)
    {
        if (isLeaf(node))
        {
            return currentSum + node->val == target;
        }
        else
        {
            currentSum = currentSum + node->val;
            if (node->left != nullptr &&
                traverse(node->left, currentSum, target))
            {
                return true;
            }
            else if (node->right != nullptr &&
                     traverse(node->right, currentSum, target))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

#endif // PATHSUM_HPP
