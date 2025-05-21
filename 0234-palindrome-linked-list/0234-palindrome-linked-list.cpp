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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        ListNode* rev = nullptr;
        ListNode* next = nullptr;
        while(temp){
            next = temp->next;
            temp->next = rev;
            rev = temp;
            temp = next;
        }

        slow->next = rev;
        slow = slow->next;

        while(slow){
            if(head->val != slow->val) return false;
            slow = slow->next;
            head = head->next;
        }

        return true;
    }
};