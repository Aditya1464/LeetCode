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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = slow->next;

        int twinSum = 0;

        ListNode* rev = new ListNode();
        ListNode* temp = head;

        while(temp){
           ListNode* newNode = new ListNode(temp->val);
           if(rev->val == 0){
            rev = newNode;
           }
           else{
            newNode->next = rev;
            rev = newNode;
           }

           temp = temp->next;
        }

        while(head != slow){
            twinSum = max(twinSum, head->val + rev->val);
            head = head->next;
            rev = rev->next;
        }

        return twinSum;
    }
};