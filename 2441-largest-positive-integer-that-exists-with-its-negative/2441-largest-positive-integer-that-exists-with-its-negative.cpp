class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        map<int, int> map;
        for(int i=0; i<nums.size(); i++){

            if(map.count(-nums[i])){
                return abs(nums[i]);
            }
            map[nums[i]]++;
        }
        return -1;
    }
};