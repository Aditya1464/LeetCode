class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);

        temp[n-1] = 0;

        for(int i = n - 2; i>=0; i--){

            if(nums[i] == 0){
                temp[i] = 10001;
                continue;
            }

            int minm = INT_MAX;

            for(int j = i+1; j <= i + nums[i]; j++){
                if(j >= n) break;
                minm = min(minm, (temp[j] + 1));
            }

            temp[i] = minm;
        }

        return temp[0];
    }
};