class Solution {
public:

    int helper(vector<int> &nums, int n, int* ans){
        if(n == nums.size() - 1) return nums[n];

        if(ans[n] != -1) return ans[n];

        int ans1 = nums[n];
        if(n + 2 < nums.size()) ans1 += helper(nums, n+2, ans);
        int ans2 = helper(nums, n+1, ans);

        ans[n] = max(ans1, ans2);

        return ans[n];
    }

    int rob(vector<int>& nums) {
        int *ans = new int[nums.size()];

        for(int i=0; i<nums.size(); i++) ans[i] = -1;

        return helper(nums, 0, ans);
    }
};