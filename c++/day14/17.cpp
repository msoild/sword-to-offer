/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//首节点有内容
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> retVector;
        if(head == nullptr) return retVector;
        ListNode* pN = head->next;
        ListNode* pNpre = pN->next;
        int i =0;
        while(pN != nullptr) {
            i++;
            pN = pN->next;
        }
        
    }
};