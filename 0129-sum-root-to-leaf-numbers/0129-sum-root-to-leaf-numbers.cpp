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

    int ans = 0;
    int sum = 0;

    void helper(TreeNode* root) {
        if(root == nullptr){
            return ;
        }

        sum = sum * 10 + root->val;

        if(root->left == nullptr && root->right == nullptr){
            ans += sum;
            sum = (sum - root->val) / 10;
            return;
        }

        helper(root->left);
        helper(root->right);

        sum = (sum - root->val) / 10;
    }

    int sumNumbers(TreeNode* root) {
        
        helper(root);
        return ans;
    }
};