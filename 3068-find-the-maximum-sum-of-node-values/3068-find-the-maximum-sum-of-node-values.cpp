class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        vector<long long> xored(nums.size());
        long long result = 0;

        for(int i=0; i<nums.size(); i++){
            result += nums[i];
            xored[i] = (nums[i]^k) - nums[i];
            cout << xored[i] << " ";
        }
        cout << result;

        sort(xored.rbegin(), xored.rend());

        for(int i=0; i<nums.size()-1; i+=2){
            long long path_sum = xored[i] + xored[i+1];
            if(path_sum > 0) {
                result += path_sum;
            }
            else{
                break;
            }
        }

        return result;
    }
};


// class Solution {
// public:
//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//         int n = nums.size();
//         vector<long long> deltas(n); // represents how will change number after XOR
//         for (int i = 0; i < n; i++) {
//             deltas[i] = (nums[i] ^ k) - nums[i];
//         }
//         sort(deltas.rbegin(), deltas.rend());

//         long long res = 0;
//         for (int num : nums) {
//             res += num;
//         }

//         for (int startInd = 0; startInd < n - 1; startInd += 2) {
//             long long changingDelta = deltas[startInd] + deltas[startInd + 1]; // showing whether if would be beneficial if we XOR this two nodes 
//             if (changingDelta > 0) {
//                 res += changingDelta;
//             } else {
//                 break;
//             }
//         }

//         return res;
//     }
// };






// class Solution {
// public:
//     void helper(vector<int>& nums, int k, vector<vector<int>>& edges, long long& ans, int idx){
//         long long temp = 0;
//         // for(int i=0; i<nums.size(); i++){
//         //     temp += nums[i];
//         // }

//         // if(temp > ans) ans = temp;

//         if(idx == edges.size()){
//             for(int i=0; i<nums.size(); i++){
//                 temp += nums[i];
//             }

//             if(temp > ans) ans = temp;
//             return;
//         }

//         helper(nums, k, edges, ans , idx+1);

//         nums[edges[idx][0]] = nums[edges[idx][0]] ^ k;
//         nums[edges[idx][1]] = nums[edges[idx][1]] ^ k;

//         helper(nums, k, edges, ans , idx+1);
//         for(int i=0; i<nums.size(); i++){
//             temp += nums[i];
//         }

//         if(temp > ans) ans = temp;
//     }

//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//         long long ans = 0;
//         helper(nums, k, edges, ans , 0);
//         return ans;
//     }
// };