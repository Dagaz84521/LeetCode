#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(0){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* finalP = head;
        for(int i = 0; i < n; i++){
            finalP = finalP->next;
        }
        ListNode* former = 0;
        while(finalP != 0){
            former = p;
            p=p->next;
            finalP = finalP->next;
        }
        if(former == 0){
            head = p->next;
        }
        else{
            former->next = p->next;
        }
        return head;
    }
};