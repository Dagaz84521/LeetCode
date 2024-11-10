#include"../ListNode.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy = ListNode(0,head);
        ListNode* end = &dummy;
        ListNode* p = dummy.next;
        while(p){
            ListNode* q = &dummy;//需要插入的位置
            while(q->next && q->next->val < p->val){
                q = q->next;
            }
            if(q == end){
                end = p;
                p = p->next;
                continue;
            }
            end->next = p->next;
            p->next = q->next;
            q->next = p;
            p = end->next;
        }
        return dummy.next;
    }
};