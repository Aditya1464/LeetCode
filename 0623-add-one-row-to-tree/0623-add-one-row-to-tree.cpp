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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth-1 == 1){
            
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root->left = newLeft;
            root->right = newRight;
            newLeft->left = left;
            newRight->right = right;
        }
        else if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        else{
            if(root->left) root->left = addOneRow(root->left, val, depth-1);
            if(root->right) root->right = addOneRow(root->right, val, depth -1);
        }

        return root;
    }
};