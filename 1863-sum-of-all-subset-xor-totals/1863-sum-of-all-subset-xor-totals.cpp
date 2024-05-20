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
            subset.push_back(temp);
        }

        for(int i=0; i<n; i++){
            subset[i].push_back(nums[idx]);
        }

        // for(int i=0; i<subset.size(); i++){
        //     for(int j=0; j<subset[i].size(); j++) cout << subset[i][j] << " ";
        //     cout << endl;
        // }
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subset;
        helper(nums, subset, 0);
        int ans = 0;

        // for(int i=0; i<subset.size(); i++){
        //     for(int j=0; j<subset[i].size(); j++) cout << subset[i][j] << " ";
        //     cout << endl;
        // }

        for(int i=0; i<subset.size(); i++){
            int k = 0;
            for(int j=0; j<subset[i].size(); j++) k = k ^ subset[i][j];
            ans += k;
        }

        return ans;
    }
};