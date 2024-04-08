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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* curr = head;
        if(!head->next) return head;
        ListNode* slow = head->next;
        if(!head->next->next){
            if(head->val == head->next->val){
                head->next = nullptr;
            }
            return head;
        }
        ListNode* fast = head->next->next;

        while(fast){
            if(curr->val == slow->val){
                curr->next = fast;
                slow = fast;
                fast = fast->next;
            }
            else{
                curr = slow;
                slow = fast;
                fast = fast->next;
            }
        }

        if(curr->val == slow->val) curr->next = nullptr;

        return head;
    }
};