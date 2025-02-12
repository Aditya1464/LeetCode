class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        for(auto n : nums){
            int it = n;
            int sum = 0;
            while(it != 0){
                sum += it % 10;
                it /= 10;
            }

            map[sum].push_back(n);
        }

        int ans = -1;
        for(auto it: map){
            if(it.second.size() <= 1) continue;

            sort(it.second.begin(), it.second.end());
            int i = it.second.size() - 1;
            int j = it.second.size() - 2;
            ans = max(ans, it.second[i] + it.second[j]);
        }

        return ans;
    }
};