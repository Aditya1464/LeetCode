class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i=0;
        int countZero = 0;
        while(i < nums.size()){

            if(nums[i] == 0){

                int j = i;
                while(j < nums.size() && nums[j] == 0){
                    countZero++;
                    j++;
                }

                nums.erase(nums.begin() + i, nums.begin() + j);
            }
            else i++;
        }

        while(countZero--) nums.push_back(0);
    }
};