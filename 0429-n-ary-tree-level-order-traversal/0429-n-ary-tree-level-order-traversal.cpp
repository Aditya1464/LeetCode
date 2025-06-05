/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front == nullptr){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(nullptr);
            }
            else{

                temp.push_back(front->val);
                for(auto &child: front->children) q.push(child);
            }
        }

        return ans;
    }
};