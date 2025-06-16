class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minm = INT_MAX, maxm = 0;
        int ans = -1;
        for(int &i : nums){
            if(i < minm){
                minm = i;
                maxm = i;
            }
            else if(i > minm && i > maxm) maxm = i;
            if(minm != maxm) ans = max(ans, maxm-minm);
        }
        return ans;
    }
};