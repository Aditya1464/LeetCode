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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == nullptr || head->next == nullptr) return head;

        int m = 0;

        int size = 0;
        ListNode* temp4 = head;

        while(temp4 != nullptr){
            temp4 = temp4->next;
            size++;
        }

        while(m + k <= size){

            int left = m;
            int right = left + k;

            while(left < right){
                int i = left + 1;
                int j = right;

                ListNode* temp1 = head;
                ListNode *temp2 = head;

                while(--i){
                    temp1 = temp1->next;
                }   
            
                while(--j && temp2->next != nullptr){
                    temp2 = temp2->next;
                }

                cout << temp1->val << " " << temp2->val;

                int temp = temp1->val;
                temp1->val = temp2->val;
                temp2->val = temp;
                
                left++;
                right--;
            }

            m = m + k;
        }

        return head;
    }
};