class Solution {
public:

    bool isValid(vector<vector<int>>& grid, int i, int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j] != 0; 
    }

    void helper(vector<vector<int>>& grid, int temp, int& ans, int i, int j){

        if(!isValid(grid, i, j)){
            ans = max(ans, temp);
            return;
        }

        int n = grid[i][j];
        temp += n;
        grid[i][j] = 0;

        //top
        helper(grid, temp, ans, i-1, j);
        //left
        helper(grid, temp, ans, i, j-1);
        //right
        helper(grid, temp, ans, i, j+1);
        //bottom
        helper(grid, temp, ans, i+1, j);


        grid[i][j] = n;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] != 0){
                    helper(grid, 0, ans, i, j);
                }
            }
        }

        return ans;
    }
};