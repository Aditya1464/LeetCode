class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans = 0;
        int i=0;
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());

        while(i <= nums.size() - 3){

            int j = i+1;
            int k = nums.size() - 1;

            while(j < k){

                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < minDiff){
                    ans = sum;
                    minDiff = abs(sum - target);
                    // k--;
                    // continue;
                }

                if(sum - target < 0) j++;
                else k--;
            }

            i++;
        }

        return ans;
    }
};