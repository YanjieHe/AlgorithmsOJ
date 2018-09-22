#ifndef CONVERTSORTEDARRAYTOBINARYSEARCHTREE_HPP
#define CONVERTSORTEDARRAYTOBINARYSEARCHTREE_HPP
#include "common_header_files.hpp"
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
        : val{val}
        , left{nullptr}
        , right{nullptr}
    {
    }
};

class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return createTree(nums, 0, static_cast<int>(nums.size()) - 1);
    }
    TreeNode* createTree(vector<int>& nums, int low, int high)
    {
        if (low <= high)
        {
            int mid = (low + high) / 2;
            TreeNode* node = new TreeNode(nums.at(mid));
            node->left = createTree(nums, low, mid - 1);
            node->right = createTree(nums, mid + 1, high);
            return node;
        }
        else
        {
            return nullptr;
        }
    }
};

#endif // CONVERTSORTEDARRAYTOBINARYSEARCHTREE_HPP
