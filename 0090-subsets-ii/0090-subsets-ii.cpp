class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> nums, int i){
        if(i >= nums.size()){
            ans.push_back({});
            return;
        }
        
        helper(nums, i+1);

        int n = ans.size();

        for(int j=0; j<n; j++){
            vector<int> temp = vector<int>(ans[j].begin(), ans[j].end());
            temp.push_back(nums[i]);
            sort(temp.begin(), temp.end());
            
            bool isTrue = false;
            for(int k=0; k<ans.size(); k++){
                if(ans[k] == temp) {
                    isTrue = true;
                    break;
                }
            }

            if(!isTrue) ans.push_back(temp);
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }
};