class Solution {
public:

    bool zeroGre(vector<vector<int>>& grid, int col){
        int n = 0;
        for(int i=0; i<grid.size(); i++) if(grid[i][col] == 0) n++;
        if(n > grid.size() / 2) return true;
        return false;
    }

    void flipRow(vector<vector<int>>& grid, int row){
        for(int j=0; j<grid[row].size(); j++){
            if(grid[row][j] == 1) grid[row][j] = 0;
            else grid[row][j] = 1;
        }
    }

    void flipCol(vector<vector<int>>& grid, int col){
        for(int j=0; j<grid.size(); j++){
            if(grid[j][col] == 1) grid[j][col] = 0;
            else grid[j][col] = 1;
        }
    }

    int changeToDecimal(vector<int> bin){
        int ans = 0;
        int p = 0;
        for(int i=bin.size()-1; i>=0; i--){
            ans += bin[i]*pow(2, p);
            p++;
        }

        return ans;
    }

    int matrixScore(vector<vector<int>>& grid) {
        
        for(int i=0; i<grid.size(); i++){
            if(grid[i][0] == 0){
                flipRow(grid, i);
            }
        }

        for(int i=0; i<grid[0].size(); i++){
            if(zeroGre(grid, i)){
                flipCol(grid, i);
            }
        }
        
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            ans += changeToDecimal(grid[i]);
        }

        return ans;

    }
};