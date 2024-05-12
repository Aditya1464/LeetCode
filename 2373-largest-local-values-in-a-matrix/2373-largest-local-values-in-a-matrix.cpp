class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        vector<vector<int>> ans;

        // for(int i=grid.size()-1; i>=0; i--){
        //     for(int j=grid[0].size()-1; j>=0; j--){
        //         int m=0,n=0,p=0;

        //         if(i+1 < grid.size()) m = grid[i+1][j];
        //         if(j+1 < grid[0].size()) n = grid[i][j+1];
        //         if(i+1 < grid.size() && j+1 < grid[0].size()) p = grid[i+1][j+1];

        //         m = max(m, n);
        //         m = max(m, p);
        //         grid[i][j] = max(m, grid[i][j]);
        //     }
        // }

        for(int i=0; i<grid.size()-2; i++){
            vector<int> ans2;
            for(int j=0; j<grid[i].size()-2; j++){
                
                int m = max(grid[i][j], grid[i][j+1]);
                m = max(m, grid[i][j+2]);
                m = max(m, grid[i+1][j+2]);
                m = max(m, grid[i+2][j+2]);
                m = max(m, grid[i+1][j+1]);
                m = max(m, grid[i+2][j+1]);
                m = max(m, grid[i+2][j]);
                m = max(m, grid[i+1][j]);
                // m = max(m, grid[i][j+2]);

                ans2.push_back(m);
            }
            ans.push_back(ans2);
        }

        return ans;
    }
};