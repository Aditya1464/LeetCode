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

        ListNode* rev = new ListNode();
        // ListNode* temp = head;

        while(fast->next){

            ListNode* newNode = new ListNode(slow->val);
           if(rev->val == 0){
            rev = newNode;
           }
           else{
            newNode->next = rev;
            rev = newNode;
           }

           slow = slow->next;
            if(fast->next->next) fast = fast->next->next;
            else break;
        }

        int twinSum = 0;

        while(slow){
            twinSum = max(twinSum, slow->val + rev->val);
            slow = slow->next;
            rev = rev->next;
        }

        return twinSum;
    }
};