class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        cout << nums.size() ;

        if(nums.size() < nums[0]) return nums.size();
        
        for(int i=0; i<nums.size(); i++){
            int n = nums.size() - i - 1;

            if(n > nums[i] && n < nums[i+1]) return n;
            if(n+1 == nums[i]) {
                if(i-1 >= 0 && nums[i-1] == nums[i]) continue;
                return n+1;
            }
        }

        return -1;
    }
};