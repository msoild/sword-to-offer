/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy ->next = head;
        
        ListNode* p = dummy;
        
        while(p->next) {
                ListNode* q = p->next;

                while(q && p->next->val == q->val ) q = q->next;
                if(p->next->next == q) p = p->next;
                else { //delete the same node , you need to free the memory
                    while (p->next != q ) {
                        auto tmp = p->next;
                        p->next = p->next->next;
                        delete tmp;
                    }
                    
                }
            
        }
        return dummy->next;
        
    }
};