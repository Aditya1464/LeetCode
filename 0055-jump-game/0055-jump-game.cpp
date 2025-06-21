class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxJump == i && nums[i] == 0 && i != nums.size() - 1) return false;
            if(maxJump < nums[i] + i){
                maxJump = nums[i] + i;
            }
        }
        return true;
    }
};