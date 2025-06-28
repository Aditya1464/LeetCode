class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp(vector<int>(nums.begin(), nums.end()));
        sort(temp.begin(), temp.end());
        unordered_map<int, int> map;
        for (int i = temp.size() - k; i < temp.size(); ++i) {
            map[temp[i]]++;
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]]){
                map[nums[i]]--;
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};