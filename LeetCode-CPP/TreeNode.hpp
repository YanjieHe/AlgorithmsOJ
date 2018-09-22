#ifndef TREENODE_HPP
#define TREENODE_HPP
#include "common_header_files.hpp"
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val)
        : val{val}
        , left{nullptr}
        , right{nullptr}
    {
    }
    TreeNode(int val, TreeNode* left, TreeNode* right)
        : val{val}
        , left{left}
        , right{right}
    {
    }
};
void viewTree(TreeNode* node, int indent = 0)
{
    if (node != nullptr)
    {
        for (int i = 0; i < indent; i++)
        {
            cout << ' ';
        }
        cout << node->val << endl;
        viewTree(node->left, indent + 1);
        viewTree(node->right, indent + 1);
    }
}
#endif // TREENODE_HPP
