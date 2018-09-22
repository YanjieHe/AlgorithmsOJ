#ifndef LISTNODE_HPP
#define LISTNODE_HPP
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

#endif // LISTNODE_HPP
