#include<iostream>
#include"../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p = head;
        while(p){
            if(p->val == 0){
                ListNode* q = p->next;
                while(q && q->val != 0){
                    p->val += q->val;
                    q = q->next;
                }
                p->next = q;
            }
            if(p->next->next == 0){
                p->next = 0;
                break;
            }
            p = p->next;
        }
        //删除最后的0
        return head;
    }
};