// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
        
//         long long int max = *max_element(nums.begin(),nums.end());
//         long long int left = 0, right = 0, count = 0;

//         long long int ans = 0;
//         int n = nums.size();

//         while(right < nums.size()){
//             if(nums[right] == max) count++;

//             while(count >= k){
//                 ans += nums.size()-right;
//                 if(nums[right] == max) count--;
//                 left++;
//             }

//             right++;
//         }

//         // ans = n*(n+1)/2 - ans;

//         return ans;
//     }
// };


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int max_num = *max_element(nums.begin(),nums.end()),count = 0;
        long long int left = 0,right = 0,ans = 0;
        while(right<nums.size()){
            if(nums[right] == max_num)count++;
            
            while(count>=k){
                if(nums[left]==max_num)count--;
                left++;
                ans += nums.size()-right;
            }    
            right++;
        }


        return ans;
        
    }
};