/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        unordered_map<int, vector<int>> map;
        q.push({root, 0});
        map[0].push_back(root->val);
        int minm = 0, maxm = 0;
        while(!q.empty()){
            TreeNode* front = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(front->left){
                q.push({front->left, level - 1});
                map[level-1].push_back(front->left->val);
                minm = min(minm, level-1);
            }
            if(front->right){
                q.push({front->right, level+1});
                map[level + 1].push_back(front->right->val);
                maxm = max(maxm, level+1);
            }
        }
        
        for(int i=minm; i<=maxm; i++){
            sort(map[i].begin(), map[i].end());
            ans.push_back(map[i]);
        }
        
        return ans;
    }
};