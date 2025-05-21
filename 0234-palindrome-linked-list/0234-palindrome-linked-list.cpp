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
        ListNode* temp = head;
        ListNode* reverse = nullptr;

        while(temp){
            ListNode* newN = new ListNode(temp->val);
            newN->next = reverse;
            reverse = newN;
            temp = temp->next;
        }

        while(head){
            if(head->val != reverse->val) return false;
            head = head->next;
            reverse = reverse->next;
        }
        return true;
    }
};