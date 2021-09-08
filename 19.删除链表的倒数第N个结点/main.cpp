#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void dump(ListNode *head) {
    ListNode *ptr = head->next;
    std::cout << head->val;
    while (ptr != nullptr) {
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head;
        ListNode *ptr = head;
        for (int i = 0; i < n; ++i) {
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            head = front->next;
            delete front;
            return head;
        }
        ptr = ptr->next;
        while (ptr != nullptr) {
            ptr = ptr->next;
            front = front->next;
        }
        ptr = front->next;
        front->next = ptr->next;
        delete ptr;
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    while (true) {
        ListNode *head = nullptr;
        {
            int first_val;
            std::cin >> first_val;
            head = new ListNode(first_val);
        }
        ListNode *ptr = head;
        int n;
        while (true) {
            char op;
            int val;
            std::cin >> op >> val;
            if (op != ',') {
                n = val;
                break;
            }
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }
        dump(head);
        head = solution.removeNthFromEnd(head, n);
        dump(head);
    }

    return 0;
}
