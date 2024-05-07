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
    ListNode* doubleIt(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        while(temp){
            vec.push_back(temp->val);
            temp = temp->next;
        }

        int c=0;
        for(int i=vec.size()-1; i>=0; i--){
            int m = 2 * vec[i];
            vec[i] = m % 10 + c;
            c = m / 10;
        }

        if(c!=0){
            head->val = c;
            temp = head->next;
            ListNode* prev = temp;
            int i=0;
            while(temp){
                temp->val = vec[i];
                prev = temp;
                i++;
                temp = temp->next;
            }

            ListNode* newNode = new ListNode(vec[i]);
            prev->next = newNode;
        }
        else{
            temp = head;
            int i=0;
            while(temp){
                temp->val = vec[i];
                i++;

                temp = temp->next;
            }
        }

        return head;
    }
};