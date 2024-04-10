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
        if(!node->next->next){
            ListNode* p = node;
            ListNode* q = node->next;

            p->val = q->val;
            p->next = nullptr;
            return;
        }

        ListNode* p = node;
        ListNode* q = node->next;

        int n = p->val;
        p->val = q->val;
        q->val = n;

        deleteNode(q);
    }
};