class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> temp(n);

        for(int i=0; i<roads.size(); i++){
            int m = roads[i][0];
            temp[m]++;
            m = roads[i][1];
            temp[m]++;
        }

        sort(temp.begin(), temp.end());

        long long ans = 0;

        for(int i=0; i<n; i++){
            ans += temp[i]*(i+1);
        }

        return ans;
    }
};