class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){

                int min1 = INT_MAX;
                int min2 = INT_MAX;
                int min3 = INT_MAX;

                if(j-1 >= 0) min1 = grid[i+1][j-1];
                min2 = grid[i+1][j];
                if(j+1 < n) min3 = grid[i+1][j+1];

                grid[i][j] += min(min1, min(min2, min3));
            }
        }

        int min = INT_MAX;
        for(int k=0; k<n; k++) if(min > grid[0][k]) min = grid[0][k];
        return min;
    }
};