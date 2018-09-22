#ifndef MINIMUMDEPTHOFBINARYTREE_HPP
#define MINIMUMDEPTHOFBINARYTREE_HPP
#include "TreeNode.hpp"
#include "common_header_files.hpp"
#include <algorithm>
#include <limits>
class Solution
{
public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            vector<vector<TreeNode*>> result;
            int min = std::numeric_limits<int>::max();
            traverse(root, min, vector<TreeNode*>());
            return min;
        }
    }
    void traverse(TreeNode* node, int& min, vector<TreeNode*> nodes)
    {
        if (node == nullptr)
        {
            if (nodes.back()->left == nullptr && nodes.back()->right == nullptr)
            {
                min = std::min(min, static_cast<int>(nodes.size()));
            }
        }
        else
        {
            nodes.push_back(node);
            traverse(node->left, min, nodes);
            traverse(node->right, min, nodes);
        }
    }
    static void test()
    {
        Solution solution;
        TreeNode* tree =
            new TreeNode(3, new TreeNode(9),
                         new TreeNode(20, new TreeNode(15), new TreeNode(7)));
        solution.minDepth(tree);
    }
};
#endif // MINIMUMDEPTHOFBINARYTREE_HPP
