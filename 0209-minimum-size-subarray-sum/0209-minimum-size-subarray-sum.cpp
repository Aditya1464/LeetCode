class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0, right = 0, sum = 0, minL = INT_MAX;

        while(right < nums.size()){

            sum += nums[right];

            while(sum >= target){
                minL = min(minL, right-left+1);
                sum -= nums[left++];
            }

            right ++;
        }

        if(minL == INT_MAX) return 0;
        return minL;
    }
};