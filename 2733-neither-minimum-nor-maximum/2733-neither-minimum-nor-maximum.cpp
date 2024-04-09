class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxNum = std::ranges::max(nums);
        int minNum = std::ranges::min(nums);
        cout << minNum;

        for(auto i : nums){
            if(i != minNum && i != maxNum) return i;
        }

        return -1;
    }
};