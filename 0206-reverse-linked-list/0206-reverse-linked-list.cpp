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
    ListNode* reverseList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return head;
        
        vector<ListNode*> temp;

        while(head != nullptr){

            temp.push_back(head);
            head = head->next;
        }

        // reverse(temp.begin(), temp.end());

        head = temp[temp.size() - 1];

        for(int i=temp.size() - 2; i >= 0; i--){

            head->next = temp[i];
            head = head->next;
        }

        head->next = nullptr;

        return temp[temp.size()-1];
    }
};