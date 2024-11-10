#include<iostream>
#include<vector>
#include"../ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head->next;
        while(q){
            int gcd = gcdOfTwoNumbers(p->val, q->val);
            ListNode* temp = new ListNode(gcd);
            p->next = temp;
            temp->next = q;
            p = q;
            q = q->next;
        }
        return head;
    }

    int gcdOfTwoNumbers(int a, int b){
        // a should be greater than b
        if(a < b)
            return gcdOfTwoNumbers(b, a);
        if(b == 0)
            return a;
        else
            return gcdOfTwoNumbers(b, a%b);
    } 
};