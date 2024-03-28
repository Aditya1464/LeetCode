class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;

        int left = 0, right = 0, count = 0, n = nums.size();

        while(right < n){

            map[nums[right]]++;
            
            while(map[nums[right]] > k){
                map[nums[left++]]--;
            }
            
            count = max(count, right-left+1);
            right++;
        }

        return count;
    }
};