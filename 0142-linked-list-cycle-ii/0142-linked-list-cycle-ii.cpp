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

    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        if(head->next == nullptr) return nullptr;
        if(head->next->next == nullptr) return nullptr;

        while(slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }

        if(slow != fast) return nullptr;

        ListNode* ans = head;

        while(ans != fast){
            ans = ans->next;
            fast = fast->next;
        }

        return ans;
    }
};