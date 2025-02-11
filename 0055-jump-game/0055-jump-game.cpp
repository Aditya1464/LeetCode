class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums[0] == 0) return false;
        if(nums[0] >= nums.size()-1) return true;
        
        int k = -1;
        for(int i=1; i<nums.size(); i++){

            if(nums[i] >= (nums.size()-1)-i) return true;

            if(nums[i] == 0){
                bool isTrue = false;
                int l = 1;
                for(int j=i-1; j>=0; j--){
                    if(nums[j] > l){
                        isTrue = true;
                        break;
                    }
                    l++;
                }
                if(!isTrue) return false;
            }
        }

        return true;
    }
};