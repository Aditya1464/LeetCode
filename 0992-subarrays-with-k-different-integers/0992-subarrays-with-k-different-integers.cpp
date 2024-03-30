class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int left = 0, right = 0, n = nums.size(), ans1 = 0, count = 0;
        unordered_map<int, int> map;

        while(right < n){

            if(map[nums[right]]++ == 0) count++;
            
            while(count >= k){
                if(--map[nums[left++]] == 0) count--;
            }

            ans1 += right - left + 1;
            right++;
        }

        left = 0;
        right = 0;
        count = 0;
        int ans2 = 0;
        unordered_map<int, int> map1;

        while(right < n){

            if(map1[nums[right]]++ == 0) count++;
            
            while(count > k){
                if(--map1[nums[left++]] == 0) count--;
            }

            ans2 += right - left + 1;
            right++;
        }

        return ans2 - ans1;

    }
};