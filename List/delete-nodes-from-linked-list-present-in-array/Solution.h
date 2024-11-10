#include"../ListNode.h"
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        ListNode* p = head;
        ListNode dummy(0, head);
        ListNode* q = &dummy;
        while(p){
            if(s.find(p->val)!=s.end()){
                q->next = p->next;
                p = p->next;
            }else{
                q = p;
                p = p->next;
            }
        }    
        return dummy.next; 
    }
};