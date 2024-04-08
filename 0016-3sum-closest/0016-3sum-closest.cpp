class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans = 0, i=0, minDiff = INT_MAX;
        sort(nums.begin(), nums.end());

        while(i <= nums.size() - 3){
            
            if(i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }

            int j = i+1, k = nums.size() - 1;

            while(j < k){

                int sum = nums[i] + nums[j] + nums[k];
            
                if(abs(sum - target) < minDiff){
                    ans = sum;
                    minDiff = abs(sum - target);
                    if(minDiff == 0) return target;
                }

                if(sum - target < 0) j++;
                else k--;
            }

            i++;
        }

        return ans;
    }
};