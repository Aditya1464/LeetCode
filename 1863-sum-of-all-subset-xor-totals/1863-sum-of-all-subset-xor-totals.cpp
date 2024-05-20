class Solution {
public:
    int helper(vector<int> nums, int idx, int current){
        if(idx == nums.size()) return current;

        int with = helper(nums, idx+1, current^nums[idx]);
        int without = helper(nums, idx+1, current);

        return with + without;
    }

    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};