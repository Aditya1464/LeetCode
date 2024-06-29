class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        // vector<vector<int>> temp(n, vector<int>(2, 0));
        vector<long long> temp(n);

        // for(int i=0; i<n; i++){
        //     temp[i][1] = i;
        // }

        for(int i=0; i<roads.size(); i++){

            int m = roads[i][0];
            temp[m]++;
            m = roads[i][1];
            temp[m]++;
        }

        sort(temp.begin(), temp.end());
        // cout << temp[0][0] << " " << temp[0][1];

        long long ans = 0;

        for(int i=0; i<n; i++){
            ans += temp[i]*(i+1);
        }

        return ans;
    }
};