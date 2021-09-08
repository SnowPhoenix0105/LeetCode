#include <iostream>
#include <vector>
#include <sstream>

using std::vector;

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

void mark(int i) {
    std::cout << i;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> srcptrs(lists);
        size_t srcptrs_size = srcptrs.size();
        ListNode head;
        ListNode *ptr = &head;

        int min_val = -1 - 0x7fffffff;
        while (true) {
            bool flag = true;
            size_t min_index = srcptrs_size;
            for (size_t i = 0; i != srcptrs_size; ++i) {
                auto srcptr = srcptrs[i];
                if (srcptr == nullptr) continue
                flag = false;
                if (min_index == srcptrs_size || srcptr->val < min_val) {
                    min_val = srcptr->val;
                    min_index = i;
                }
            }
            if (flag) {
                return head.next;
            }
            ptr->next = srcptrs[min_index];
            // std::cout << ptr->next << ' ' << srcptrs[min_index] <<  '\n';
            // dump(ptr);
            ptr = ptr->next;
            // dump(ptr);
            srcptrs[min_index] = ptr->next;
            // dump(head.next);
        }
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
        int num;
        std::cout << "start\n";
        std::cin >> num;
        std::getchar();
        vector<ListNode*> lists;
        lists.reserve(num);
        for (int i = 0; i < num; ++i) {
            auto tmp = readList();
            lists.push_back(tmp);
            dump(tmp);
        }

        ListNode *head = solution.mergeKLists(lists);
        dump(head);
        while (head != nullptr) {
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    return 0;
}
