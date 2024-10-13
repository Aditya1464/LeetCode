class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int> temp;
        int k = 0;

        for(int i=0; i<nums.size(); i++){

            if(val == nums[i]){
                temp.push(i);
            }
            else{
                k++;
                if(temp.size() != 0){
                    int idx = temp.front();
                    temp.pop();
                    nums[idx] = nums[i];
                    temp.push(i);
                }
            }
        }

        return k;
    }
};