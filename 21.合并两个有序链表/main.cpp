#include <iostream>
#include <vector>
#include <sstream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void dump(ListNode *head)
{
    ListNode *ptr = head->next;
    std::cout << head->val;
    while (ptr != nullptr)
    {
        std::cout << "->" << ptr->val;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode head;
        ListNode *ptr = &head;
        while (true)
        {
            if (l1->val < l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
                if (l1 == nullptr)
                {
                    ptr->next = l2;
                    return head.next;
                }
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
                if (l2 == nullptr)
                {
                    ptr->next = l1;
                    return head.next;
                }
            }
        }
        return head.next;
    }
};

ListNode *readList()
{
    std::string s;
    std::getline(std::cin, s);
    std::istringstream ss(s);
    ListNode head;
    ListNode *ptr = &head;
    int val;
    while (ss >> val)
    {   
        // std::cout << "get" << val << '\n';
        ptr->next = new ListNode(val);
        ptr = ptr->next;
    }
    return head.next;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    while (true)
    {
        ListNode *head1 = readList();
        ListNode *head2 = readList();
        dump(head1);
        dump(head2);
        head1 = solution.mergeTwoLists(head1, head2);
        dump(head1);
    }

    return 0;
}
