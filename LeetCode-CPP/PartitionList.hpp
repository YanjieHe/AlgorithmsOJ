#ifndef PARTITIONLIST_HPP
#define PARTITIONLIST_HPP
#include "common_header_files.hpp"
class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int val)
        : val{val}
        , next{nullptr}
    {
    }
    ListNode(int val, ListNode* next)
        : val{val}
        , next{next}
    {
    }
};

class SinglyLinkedList
{
public:
    ListNode* head;
    ListNode* tail;
    SinglyLinkedList()
        : head{nullptr}
        , tail{nullptr}
    {
    }
    void append(int val)
    {
        if (head == nullptr)
        {
            head = new ListNode(val);
            tail = head;
        }
        else
        {
            auto node = new ListNode(val);
            tail->next = node;
            tail = node;
        }
    }
};

class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        SinglyLinkedList list2;
        while (head != nullptr && head->val >= x)
        {
            list2.append(head->val); // store head node that >= x
            head = head->next;
        }
        if (head == nullptr)
        {
            return list2.head;
        }
        ListNode* previous = head;
        ListNode* current = head->next;
        while (current != nullptr)
        {
            if (current->val >= x)
            {
                list2.append(current->val); // store nodes that >= x
                previous->next = current->next;
                current = current->next;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        concateTwoList(head, list2);
        return head;
    }
    void concateTwoList(ListNode* head, SinglyLinkedList& list2)
    {
        ListNode* previous = head;
        ListNode* current = previous->next;
        while (current != nullptr)
        {
            previous = current;
            current = current->next;
        }
        previous->next = list2.head;
    }
    static void printList(ListNode* head)
    {
        ListNode* current = head;
        while (current != nullptr)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
    static void test()
    {
        ListNode* list = new ListNode(
            1,
            new ListNode(
                4, new ListNode(
                       3, new ListNode(2, new ListNode(5, new ListNode(2))))));
        printList(list);
        Solution solution;
        printList(solution.partition(list, 3));
    }
};

#endif // PARTITIONLIST_HPP
