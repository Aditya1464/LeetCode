class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
      long long ans=0;
      int maxI=-1;
      int minI=-1;
      int start=0;
      for(int i=0;i<n;i++){
          if(nums[i]<minK || nums[i]>maxK){
              minI=maxI=-1;
              start=i+1;
          }
          if(nums[i]==minK){
              minI=i;
          }
          if(nums[i]==maxK){
              maxI=i;
          }
          ans=ans+max(0,min(minI,maxI)-start+1);
      }
      return ans;
    }
};