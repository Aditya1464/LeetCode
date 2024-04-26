class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        vector<int> temp;
        int n = grid.size();
        for(int i=0; i<n; i++) temp.push_back(grid[n-1][i]);

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int min = INT_MAX;
                for(int k=0; k<n; k++) if(k!=j && min > temp[k]) min = temp[k];
                grid[i][j] += min;
            }

            temp.clear();
            for(int k=0; k<n; k++) temp.push_back(grid[i][k]);
        }

        int min = INT_MAX;
        for(int k=0; k<n; k++) if(min > temp[k]) min = temp[k];
        return min;
    }
};






// class Solution {
// public:
//     void helper(vector<vector<int>>& grid, int row, int idx, int& temp, int& ans){
//         if(row == grid.size()){
//             if(temp < ans) ans = temp;
//             return;
//         }

//         for(int i=0; i<grid.size(); i++){
//             if(i == idx) continue;
//             temp += grid[row][i];
//             helper(grid, row+1, i, temp, ans);
//             temp -= grid[row][i];
//         }
//     }

//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int temp = 0, ans = INT_MAX;
//         helper(grid, 0, -1, temp, ans);
//         return ans;
//     }
// };