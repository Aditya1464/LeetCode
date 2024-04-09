class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        
        int max = 0, min = 101;

        for(auto i : nums){
            if(i > max) max = i;
            if(i < min) min = i;
        }

        for(auto i : nums){
            if(i != min && i != max) return i;
        }

        return -1;
    }
};