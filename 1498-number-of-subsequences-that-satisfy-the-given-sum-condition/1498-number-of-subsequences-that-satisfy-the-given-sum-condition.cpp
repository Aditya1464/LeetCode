class Solution {
long long modPowerOfTwo(long long n, long long mod) {
    long long result = 1, base = 2;
    while (n > 0) {
        if (n % 2 == 1)
            result = (result * base) % mod;
            base = (base * base) % mod;
            n /= 2;
    }
    return result;
}
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minIdx = 0, maxIdx = nums.size() - 1;
        int ans = 0;
        long long mod = 1e9 + 7;

        while(minIdx < maxIdx){
            if(nums[minIdx] + nums[maxIdx] > target){
                maxIdx--;
            }
            else{
                ans += modPowerOfTwo(maxIdx-minIdx, mod);
                ans %= mod;
                minIdx++;
            }
        }
        if(nums[minIdx] * 2 <= target) ans++;
        return ans;
    }
};