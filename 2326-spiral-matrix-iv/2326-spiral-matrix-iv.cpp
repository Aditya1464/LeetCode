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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int k = 0, l = 0, o = 0, p = 0;
        while(head){
            int i = l, j = k;

            while(j < (n-o) && head){
                ans[i][j] = head->val;
                j++;
                // if(j < (n-o)) 
                head = head->next;
            }
            if(head) cout << head->val << " i :" << i << " j :" << j << endl;

            j--;
            i++;

            while(i < (m-p) && head){
                ans[i][j] = head->val;
                i++;
                // if(i < (m-p)) 
                head = head->next;
            }
            if(head) cout << head->val<<  " i :" << i << " j :" << j << endl;

            i--;
            j--;

            while(j >= k && head){
                ans[i][j] = head->val;
                j--;
                // if(j >= k) 
                head = head->next;
            }
            if(head) cout << head->val <<  " i :" << i << " j :" << j << endl;

            j++;
            i--;

            while(i > l && head){
                ans[i][j] = head->val;
                i--;
                // if(i > l) 
                head = head->next;
            }

            // break;
            if(head) cout << head->val <<  " i :" << i << " j :" << j << endl;
            k++;
            l++;
            o++;
            p++;
        } 

        return ans;
    }
};