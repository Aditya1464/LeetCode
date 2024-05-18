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
    int helper(TreeNode* root, int& ans){
        if(root == nullptr) return 0;
        root->val += helper(root->left, ans);
        root->val += helper(root->right, ans);

        if(root->val == 1) return 0;
        else{
            int n = root->val - 1;
            root->val = 1;
            ans += abs(n);
            return n;
        }
    }

    int distributeCoins(TreeNode* root) {
        int ans = 0;
        int n = helper(root, ans);
        return ans;
    }
};