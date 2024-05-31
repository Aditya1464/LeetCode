class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> map;

        for(int i=0; i<nums.size(); i++) map[nums[i]]++;

        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == 1) ans.push_back(nums[i]);
        }

        return ans;
    }
};