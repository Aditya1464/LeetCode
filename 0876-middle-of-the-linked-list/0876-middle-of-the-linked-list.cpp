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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        if(slow->next == nullptr) return slow;
        if(fast->next->next == nullptr) return fast->next;

        while(fast->next != nullptr){
            if(fast->next->next == nullptr) return slow->next;

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};