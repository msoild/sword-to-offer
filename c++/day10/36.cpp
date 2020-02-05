/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //l1 的数大于等于都放前面
 // l1  l2 chang
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
         
        while(l1 && l2) {
          ListNode* newNext = nullptr;
         
          if(l1->val <= l2->val) newNext = l1, l1 = l1->next;
          else newNext = l2, l2 = l2->next;
          
          p->next = newNext;
          p = p->next;
        }
        
        
         if(l1) p->next = l1;
         else  p->next = l2;
          
        ListNode* retP = dummy->next;
        delete dummy;
        return retP;
        
    }  
};