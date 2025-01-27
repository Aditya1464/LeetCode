class Solution {
    private:
    bool isValid(vector<vector<int>> & mat, int i, int j){
        return i>=0 && i<mat.size() && j>=0 && j<mat[0].size() && mat[i][j] == 1;
    }
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        q.push({-1, -1});
        int ans = 0;
        
        while(!q.empty()){
            
            int i = q.front().first;
            int j = q.front().second;
            
            q.pop();
            
            if(i==-1 && j == -1){
                if(q.size() != 0){
                    q.push({-1, -1});
                    ans++;
                }
                continue;
            }
            
            if(isValid(mat, i+1, j)){
                q.push({i+1, j});
                mat[i+1][j] = 2;
            }
            if(isValid(mat, i-1, j)){
                q.push({i-1, j});
                mat[i-1][j] = 2;
            }
            if(isValid(mat, i, j+1)){
                q.push({i, j+1});
                mat[i][j+1] = 2;
            }
            if(isValid(mat, i, j-1)){
                q.push({i, j-1});
                mat[i][j-1] = 2;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};