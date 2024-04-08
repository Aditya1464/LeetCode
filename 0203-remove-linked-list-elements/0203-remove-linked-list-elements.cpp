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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) head = head->next;

        if(!head) return head;
        if(!head->next){
            if(head->val == val) return nullptr;
            else return head;
        }
        if(!head->next->next){
            if(head->val == val && head->next->val == val) return nullptr;
            if(head->val == val){
                return head->next;
            }
            if(head->next->val == val){
                head->next = nullptr;
                return head;
            }
        }
        
        ListNode* curr = head;
        ListNode* prev = head;
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;

        while(fast){
            if(slow->val == val){
                curr->next = fast;
                slow = fast;
                fast = fast->next;
            }
            else{
                prev = curr;
                curr = slow;
                slow = fast;
                fast = fast->next;
            }
        }

        if(slow->val == val) curr->next = nullptr;

        if(curr->val == val){
            if(curr == prev) return nullptr;
            else{
                prev->next = nullptr;
                return head;
            }
        }

        return head;
    }
};