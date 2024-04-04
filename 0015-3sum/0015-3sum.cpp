class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        vector<vector<int>> ans;
        while(i <= nums.size() - 3){
            int n = nums[i];

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){
                vector<int> vec;

                if(n + nums[j] + nums[k] == 0){
                    vec.push_back(n);
                    vec.push_back(nums[j]);
                    vec.push_back(nums[k]);
                    ans.push_back(vec);

                    while(j + 1 < nums.size() && nums[j] == nums[j+1]) j++;
                    j++;
                    while(k-1 >= 0 && nums[k] == nums[k-1]) k--;
                    k--;
                }
                else if(n + nums[j] + nums[k] > 0){
                    while(k-1 >= 0 && nums[k] == nums[k-1]) k--;
                    k--;
                }
                else{
                    while(j + 1 < nums.size() && nums[j] == nums[j+1]) j++;
                    j++;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
            i++;
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int i=0;
//         vector<vector<int>> ans;

//             int n = nums[i];

//             int j = i + 1;
//             int k = nums.size() - 1;

//             while(j < k){
//                 vector<int> vec;

//                 if(n + nums[j] + nums[k] == 0){
//                     vec.push_back(n);
//                     vec.push_back(nums[j]);
//                     vec.push_back(nums[k]);
//                     bool isExist = false;

//                     // for(int l = 0; l<ans.size(); l++){
//                     //     if(ans[l] == vec){
//                     //         isExist = true;
//                     //         break;
//                     //     }
//                     // }
                    
//                     if(!isExist) ans.push_back(vec);
//                     while(nums[j] == nums[j+1]) j++;
//                     j++;
//                     while(nums[k] == nums[k-1]) k--;
//                     k--;
//                 }
//                 else if(n + nums[j] + nums[k] > 0){
//                     while(nums[k] == nums[k-1]) k--;
//                     k--;
//                 }
//                 else {
//                     while(nums[j] == nums[j+1]) j++;
//                     j++;
//                 }

//                 if(j >= k){
//                     i++;
//                     if(i > nums.size() - 3) break;
//                     n = nums[i];
//                     j = i + 1;
//                     k = nums.size() - 1;
//                 }
//             }
//             i++;
//         // }
//         return ans;
//     }
// };