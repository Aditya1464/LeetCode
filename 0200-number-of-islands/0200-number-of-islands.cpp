class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int i, int j){
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == '1';
    }

    void helper(vector<vector<char>>& grid, int i, int j){

        if(!isValid(grid, i, j)) return;
        grid[i][j] = '0';

        helper(grid, i, j+1);
        helper(grid, i, j-1);
        helper(grid, i+1, j);
        helper(grid, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    helper(grid, i, j);
                    count ++;
                }
            }
        }

        return count;
    }
};