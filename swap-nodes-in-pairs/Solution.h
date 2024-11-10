#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(0){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == 0 || head->next == 0){
            return head;
        }
        ListNode* newHead = head->next;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* former = 0;
        while(p!=0 && q!=0){
            p->next = q->next;
            q->next = p;
            if(former != 0 ){
                former->next = q;
            }
            former = p;
            p = p->next;
            q = p == 0 ? 0 : p->next;
        }
        return newHead;
    }
};