class Solution {
public:
    bool isValid(vector<vector<char>>& grid, vector<vector<int>>& visit, int i, int j){
        return i >= 0 && j >= 0 && i < visit.size() && j < visit[0].size() && visit[i][j] == 0 && grid[i][j] == '1';
    }

    void helper(vector<vector<char>>& grid, vector<vector<int>>& visit, int i, int j){

        if(!isValid(grid, visit, i, j)) return;
        visit[i][j] = 1;

        helper(grid, visit, i, j+1);
        helper(grid, visit, i, j-1);
        helper(grid, visit, i+1, j);
        helper(grid, visit, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));

        int count = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){

                if(grid[i][j] == '1' && visit[i][j] == 0){
                    helper(grid, visit, i, j);
                    count ++;
                }
            }
        }

        return count;
    }
};