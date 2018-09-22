#ifndef CONVERTSORTEDLISTTOBINARYSEARCHTREE_HPP
#define CONVERTSORTEDLISTTOBINARYSEARCHTREE_HPP
#include "ListNode.hpp"
#include "TreeNode.hpp"
#include "common_header_files.hpp"
class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        else
        {
            return makeTree(head, nullptr);
        }
    }
    TreeNode* makeTree(ListNode* head, ListNode* tail)
    {
        if (head == tail)
        {
            return nullptr;
        }
        else if (head->next == tail)
        {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        else
        {
            ListNode* mid = head;
            ListNode* current = head;
            while (current != tail && current->next != tail)
            {
                mid = mid->next;
                current = current->next->next;
            }
            TreeNode* root = new TreeNode(mid->val);
            root->left = makeTree(head, mid);
            root->right = makeTree(mid->next, tail);
            return root;
        }
    }
    static void test()
    {
        Solution solution;
        ListNode* list = new ListNode(
            -10, new ListNode(
                     -3, new ListNode(0, new ListNode(5, new ListNode(9)))));
        auto tree = solution.sortedListToBST(list);
        viewTree(tree);
    }
};
#endif // CONVERTSORTEDLISTTOBINARYSEARCHTREE_HPP
