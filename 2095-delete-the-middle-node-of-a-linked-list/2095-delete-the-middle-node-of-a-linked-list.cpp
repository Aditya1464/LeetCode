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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while(temp){
            n++;
            temp = temp->next;
        }

        if(n%2) n = (n-1)/2;
        else n = n/2;
        if(n==0) return nullptr;
        temp = head;
        while( n != 1){
            n--;
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};