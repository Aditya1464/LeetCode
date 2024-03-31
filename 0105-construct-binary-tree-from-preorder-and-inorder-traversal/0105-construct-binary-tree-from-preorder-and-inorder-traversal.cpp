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

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(preorder[ps]);

        if(ps == pe && is == ie){
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        
        int s = -1;
        for(int i=is; i<(ie+1); i++){
            if(inorder[i] == preorder[ps]){
                s = i;
                break;
            }
        }

        s = s - is;

        root->left = helper(preorder, inorder, ps+1, ps+s, is,  is+s-1);
        root->right = helper(preorder, inorder, ps+s+1, pe, is+s+1, ie);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};