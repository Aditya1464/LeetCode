class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        vector<int> temp;
        
        for(int k=1; k<=n; k++){

            int sum = 0;
            int i = 0;
            while(i < k) {
                sum += nums[i];
                i++;
            }

            temp.push_back(sum);

            int j = 0;

            while(j < n-k){
                sum += nums[i];
                sum -= nums[j];
                i++;
                j++;
                temp.push_back(sum);
            }
        }

        sort(temp.begin(), temp.end());

        int ans = 0;
        int mod = 1000000007;

        for(int i = left-1; i<right; i++) {
            ans += temp[i];
            ans %= mod;
        }

        return ans;
    }
};