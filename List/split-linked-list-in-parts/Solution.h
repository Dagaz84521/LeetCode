#include<vector>
#include"../ListNode.h"
using namespace std;
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* p = head;
        while(p){
            cnt++;
            p = p->next;
        }
        int n = cnt/k, m = cnt%k;
        vector<ListNode*> res;
        p = head;
        for(int i = 0; i < k; i++){
            ListNode* q = p;
            for(int j = 1; j < n + (i < m); j++){
                if(p){
                    p = p->next;
                }
            }
            if(q){
                res.push_back(q);
                if(p){
                    q = p;
                    p = p->next;
                    q->next = 0;
                }
            }else{
                res.push_back(0);
            }
        }
        return res;
    }
};