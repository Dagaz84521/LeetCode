#include"../ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* p = &dummy;
        while(p->next){
            ListNode* q = p->next;
            while(q->next && q->val == q->next->val){
                q = q->next;
            }
            if(p->next == q){
                p = p->next;
            }else{
                p->next = q->next;
            }
        }
        return dummy.next;
    }
};