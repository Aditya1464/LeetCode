/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    Node* cpy(Node* head){
        if(!head) return head;
        Node* newN = new Node(head->val);
        newN->next = cpy(head->next);
        return newN;
    }
public:
    Node* copyRandomList(Node* head) {
        Node* newN = nullptr;
        newN = cpy(head);

        unordered_map<Node*, int> old;
        unordered_map<int, Node*> newM;

        Node* temp = head;
        int i=0;
        while(temp){
            old[temp] = i;
            i++;
            temp = temp->next;
        }

        temp = newN;
        i=0;
        while(temp){
            newM[i] = temp;
            i++;
            temp = temp->next;
        }

        temp = head;
        Node* temp2 = newN;

        while(temp){
            if(temp->random){
                temp2->random = newM[old[temp->random]];
            }
            temp = temp->next;
            temp2 = temp2->next;
        }

        return newN;
    }
};