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
        // if(!node->next->next){
        //     ListNode* p = node;
        //     p->val = p->next->val;
        //     p->next = nullptr;
        //     return;
        // }

        // ListNode* p = node;

        // int n = p->val;
        // p->val = p->next->val;
        // p->next->val = n;

        // deleteNode(p->next);

        while(node->next->next){
            int n = node->val;
            node->val = node->next->val;
            node->next->val = n;
            node = node->next;
        }

        node->val = node->next->val;
        node->next = nullptr;
        return;
    }
};