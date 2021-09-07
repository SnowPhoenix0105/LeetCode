/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int value;
    int overflow = 0;
    Node* p1 = l1;
    Node* p2 = l2;
    Node* head = NULL;
    Node* tail = NULL;
    while( p1!=NULL && p2!=NULL ){
        value = p1->val + p2->val + overflow;
        overflow = value >= 10;
        if(head==NULL){
            head = (Node*)malloc(sizeof(Node));
            tail = head;
        }
        else{
            tail->next = (Node*)malloc(sizeof(Node));
            tail = tail->next;
        }
        tail->val = value % 10;
        p1 = p1->next;
        p2 = p2->next;
    }
    while( p1!=NULL ){
        value = p1->val + overflow;
        overflow = value >= 10;
        tail->next = (Node*)malloc(sizeof(Node));
        tail = tail->next;
        tail->val = value % 10;
        p1 = p1->next;
    }
    while( p2!=NULL ){
        value = p2->val + overflow;
        overflow = value >= 10;
        tail->next = (Node*)malloc(sizeof(Node));
        tail = tail->next;
        tail->val = value % 10;
        p2 = p2->next;
    }
    if(overflow){
        tail->next = (Node*)malloc(sizeof(Node));
        tail = tail->next;
        tail->val = overflow;
        tail->next = NULL;
    }
    else{
        tail->next = NULL;
    }
    return(head);
}