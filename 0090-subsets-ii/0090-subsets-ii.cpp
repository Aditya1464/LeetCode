class Solution {
public:
    vector<vector<int>> ans;
    // unordered_set<vector<int>> set;
    void helper(vector<int> nums, int i){
        if(i >= nums.size()){
            ans.push_back({});
            return;
        }
        helper(nums, i+1);

        int n = ans.size();
        for(int j=0; j<n; j++){
            ans.push_back(ans[j]);
        }

        for(int j=n; j<ans.size(); j++){
            ans[j].push_back(nums[i]);
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        helper(nums, 0);
        vector<vector<int>> sub;

        for(int i=0; i<ans.size(); i++){
            bool isTrue = false;
            sort(ans[i].begin(), ans[i].end());
            for(int j=0; j<sub.size(); j++){
                if(sub[j] == ans[i]){
                    isTrue = true;
                    break;
                }
            }
            if(!isTrue) sub.push_back(ans[i]);
        }
        return sub;
    }
};