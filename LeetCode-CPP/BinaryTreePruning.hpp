#ifndef BINARYTREEPRUNING_HPP
#define BINARYTREEPRUNING_HPP
#include <iostream>
using std::cout;
using std::endl;
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x)
        : val{x}
        , left{NULL}
        , right{NULL}
    {
    }
    TreeNode(int val, TreeNode* left, TreeNode* right)
        : val{val}
        , left{left}
        , right{right}
    {
    }
};

class Solution
{
public:
    TreeNode* filterTree(TreeNode* node)
    {
        if (node != nullptr)
        {
            auto left = filterTree(node->left);
            auto right = filterTree(node->right);
            if (node->val == 0)
            {
                if (left == nullptr && right == nullptr)
                {
                    return nullptr;
                }
                else
                {
                    return rewriteChildren(node, left, right);
                }
            }
            else
            {
                return rewriteChildren(node, left, right);
            }
        }
        else
        {
            return nullptr;
        }
    }
    TreeNode* rewriteChildren(TreeNode* parent, TreeNode* left, TreeNode* right)
    {
        parent->left = left;
        parent->right = right;
        return parent;
    }
    TreeNode* pruneTree(TreeNode* root)
    {
        if (root != nullptr)
        {
            auto left = pruneTree(root->left);
            auto right = pruneTree(root->right);
            if (root->val == 0)
            {
                if (left == nullptr && right == nullptr)
                {
                    return nullptr;
                }
                else
                {
                    return rewriteChildren(root, left, right);
                }
            }
            else
            {
                return rewriteChildren(root, left, right);
            }
        }
        else
        {
            return nullptr;
        }
    }
    static void displayTree(TreeNode* node, int depth)
    {
        if (node != nullptr)
        {
            printIndentation(depth * 4);
            cout << node->val << endl;
            displayTree(node->left, depth + 1);
            displayTree(node->right, depth + 1);
        }
    }
    static void printIndentation(int indent)
    {
        for (int i = 0; i < indent; i++)
        {
            cout << ' ';
        }
    }
    static void displayOperation(TreeNode* tree)
    {
        cout << "before" << endl;
        displayTree(tree, 0);
        Solution solution;
        cout << "after" << endl;
        displayTree(solution.pruneTree(tree), 0);
    }
    static void test1()
    {
        TreeNode* tree = new TreeNode(
            1, nullptr, new TreeNode(0, new TreeNode(0), new TreeNode(1)));
        displayOperation(tree);
    }
    static void test2()
    {
        TreeNode* tree =
            new TreeNode(1, new TreeNode(0, new TreeNode(0), new TreeNode(0)),
                         new TreeNode(1, new TreeNode(0), new TreeNode(1)));
        displayOperation(tree);
    }
    static void test3()
    {
        auto tree = new TreeNode(
            1,
            new TreeNode(1, new TreeNode(1, new TreeNode(0), nullptr),
                         new TreeNode(1)),
            new TreeNode(0, new TreeNode(0), new TreeNode(1)));
        displayOperation(tree);
    }
    static void test()
    {
        test1();
        test2();
        test3();
    }
};
#endif // BINARYTREEPRUNING_HPP
