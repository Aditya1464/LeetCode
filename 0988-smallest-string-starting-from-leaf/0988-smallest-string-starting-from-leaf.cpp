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

    void helper(TreeNode* root, string& ans, string& temp){

        char ch = root->val + 97;
        temp.push_back(ch);

        if(!root->left && !root->right){
            reverse(temp.begin(), temp.end());
            if(ans[0] == 'A' || ans > temp){
                ans = temp;
            }
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            return;
        }
        
        if(root->left) helper(root->left, ans, temp);
        if(root->right) helper(root->right, ans, temp);

        temp.pop_back();
        return;
    }

    string smallestFromLeaf(TreeNode* root) {
        
        string ans, temp;
        ans.push_back('A');
        helper(root, ans, temp);
        return ans;
    }
};