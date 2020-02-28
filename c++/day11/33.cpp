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
    ListNode* findKthToTail(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;
        if (n < k) return nullptr;
        auto p = head;
        for (int i = 0; i < n - k; i ++ ) p = p->next;
        return p;
    }
};

//翻转链表法
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
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        if(k < 0 || !pListHead ) return nullptr;
       
        ListNode* cur = pListHead;
        ListNode* pre = nullptr;
        
        while(cur) {
            //1 .cache next 指针域， 2 cur->next = pre
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        int i = 0; 
        ListNode* reverseHead = pre;
        ListNode* reverseCur = reverseHead;
        while(reverseCur && i < k - 1) {
        
            reverseCur = reverseCur->next;
            i ++;
        }
        if(!reverseCur) {
            return nullptr;
        }
        return reverseCur;
        
    }
};