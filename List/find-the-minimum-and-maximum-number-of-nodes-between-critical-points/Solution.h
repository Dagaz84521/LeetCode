#include"../ListNode.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* p = head->next, *former = head, *n = p->next;
        int first = -1, last = -1, cnt = 1;
        int maxDistance = -1, minDistance = -1;
        while(n != 0){
            if((p->val>former->val && p->val>n->val)||(p->val<former->val && p->val<n->val)){
                if(first == -1){
                    first = cnt;
                }else{
                    if(minDistance == -1){
                        last = cnt;
                        minDistance = last - first;
                    }else{
                        minDistance = min(minDistance,cnt-last);
                    }
                    last = cnt;
                    maxDistance = max(maxDistance,last-first);
                }
            }
            p = p->next;
            former = former->next;
            n = n->next;
            cnt++;
        }
        return {minDistance,maxDistance};
    }
};