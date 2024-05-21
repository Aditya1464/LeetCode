class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& subset, int idx){
        if(idx == nums.size()){
            vector<int> temp(0);
            subset.push_back(temp);
            return;
        }

        helper(nums, subset, idx+1);

        int n = subset.size();
        for(int i=0; i<n; i++){
            vector<int> temp = subset[i];
            temp.push_back(nums[idx]);
            subset.push_back(temp);
        }

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> subset;
        helper(nums,subset,0);
        return subset;
    }
};