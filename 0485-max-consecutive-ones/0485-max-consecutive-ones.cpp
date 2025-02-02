class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans = 0;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == 1){
                int k = 0;
                while(i<nums.size() && nums[i] == 1){
                    i++;
                    k++;
                }

                ans = max(k, ans);
            }
            i++;
        }

        return ans;
    }
};