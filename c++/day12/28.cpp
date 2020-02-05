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
    void deleteNode(ListNode* node) {
        if(node == nullptr ) return;
        ListNode* p = nullptr;
        node->val = node->next->val;
        p = node->next;
        node->next = node->next->next;
        delete p;
    }
};