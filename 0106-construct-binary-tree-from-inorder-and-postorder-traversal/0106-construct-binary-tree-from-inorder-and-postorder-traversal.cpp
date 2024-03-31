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

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
        if(ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(postorder[pe]);

        if(ps == pe && is == ie) return root;
        
        int ls = -1;
        for(int i=is; i<(ie+1); i++){
            if(inorder[i] == postorder[pe]){
                ls = i;
                break;
            }
        }

        ls = ls - is;

        int rs = ie - ls - is;

        root->left = helper(inorder, postorder, is, is+ls-1, ps, pe-1-rs);
        root->right = helper(inorder, postorder, is+ls+1, ie, pe-rs, pe-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};

// class Solution {
// public:
//     TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
//         if (ps > pe || is > ie) return nullptr;

//         TreeNode* root = new TreeNode(postorder[pe]);

//         if (ps == pe && is == ie) return root;

//         int idx;
//         for (idx = is; idx <= ie; ++idx) {
//             if (inorder[idx] == postorder[pe]) break;
//         }

//         int ls = idx - is;
//         int rs = ie - idx;

//         root->left = helper(inorder, postorder, is, idx - 1, ps, ps + ls - 1);
//         root->right = helper(inorder, postorder, idx + 1, ie, pe - rs, pe - 1);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
//     }
// };
