/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* temp1 = head;
        head = head->next;
        temp1->next = head->next;
        head->next = temp1;

        temp1->next = swapPairs(temp1->next);
        return head;
    }
};