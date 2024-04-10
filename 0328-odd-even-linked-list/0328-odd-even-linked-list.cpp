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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode* temp = head;
        ListNode* tail = head;
        while(tail->next) tail = tail->next;

        ListNode* temp2 = tail;

        while(temp != tail){
            ListNode* even = temp->next;

            if(even == tail){
                temp->next = even->next;
                temp2->next = even;
                temp2 = even;
                break;
            }

            temp->next = even->next;
            temp2->next = even;
            temp2 = even;

            temp = temp->next;
        }

        temp2->next = nullptr;

        return head;
    }
};