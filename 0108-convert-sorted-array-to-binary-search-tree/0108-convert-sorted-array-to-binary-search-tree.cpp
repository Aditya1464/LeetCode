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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if(nums.size() == 0) return nullptr;
        
        int n = nums.size();
        
        int mid = 0;
        if(n % 2 == 0) mid = n/2 - 1;
        else mid = n/2;

        TreeNode* head = new TreeNode(nums[mid]);

        if(nums.size() == 1) return head;

        vector<int> sub1 = {nums.begin(), nums.begin() + mid};
        vector<int> sub2 = {nums.begin()+ mid + 1, nums.end()};

        head->left = sortedArrayToBST(sub1);
        head->right = sortedArrayToBST(sub2);

        return head;
    }
};