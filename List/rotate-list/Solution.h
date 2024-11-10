#include"../ListNode.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* p = head;
        while(p->next){
            n++;
            p = p->next;
        }
        n++;
        p->next = head;
        k = k % n;
        for(int i = 0; i < n-k; i++){
            p = p->next;
        }
        head = p->next;
        p->next = 0;
        return head;    
    }
};