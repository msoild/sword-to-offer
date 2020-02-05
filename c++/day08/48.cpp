/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
 /*
 step1 copy node
 step2 copy node randam
 step3 seperate the node
 */
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        for(auto p = head; p;) {
            auto next = p->next;
            auto copy = new ListNode(p->val);
            p->next = copy;
            copy->next = next;
            p = next;
        }
        
        for(auto p = head; p; p = p->next->next) {
            if(p->random) {
                p->next->random = p->random->next;
            } else {
                p->next->random = nullptr;
            }
        }
        
        auto dummy = new ListNode(-1);
        auto curP = dummy;
        for(auto p = head; p; p = p->next) {
        
            curP->next = p ->next;
            curP = curP->next;
            p->next = p->next->next;
            
        }
        return dummy->next;
        
    }
};
