class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        if(k >= nums.size()) k = nums.size() - 1;
        
        unordered_set<int> set;
        for(int i=0; i<=k; i++){
            if(set.count(nums[i]) == 1) return true;
            set.insert(nums[i]);
        }

        int j=0;
        for(int i = k + 1; i<nums.size(); i++){
            set.erase(nums[j]);
            j++;
            if(set.count(nums[i]) == 1) return true;
            set.insert(nums[i]);
        }

        return false;
    }
};