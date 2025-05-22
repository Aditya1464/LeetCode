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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr) return head;

        ListNode* temp = head;
        ListNode* tail = temp;

        int size = 0;

        while(temp != nullptr){
            size++;
            tail = temp;
            temp = temp->next;
        }
        
        if(k % size == 0) return head;
        k = k%size;

        temp = head;

        int n = size - k;

        while(--n){
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};