class Solution {
public:
    int n, m;
    vector<vector<bool>> visit;

    bool valid(vector<vector<char>>& board, int i, int j){
        return i>=0 && i<n && j>=0 && j<m && board[i][j] == 'O';
    }

    bool region(vector<vector<char>>& board, int i, int j){
        if(!valid(board, i, j) || visit[i][j]) return true;

        visit[i][j] = true;
        bool is1 = region(board, i-1, j);
        bool is2 = region(board, i+1, j);
        bool is3 =  region(board, i, j-1);
        bool is4 = region(board, i, j+1);
        visit[i][j] = false;
        
        if(is1 && is2 && is3 && is4){
            board[i][j] = 'X';
            return true;
        }

        return false;
    }

    void markEdges(vector<vector<char>>& board, int i, int j){
        if(!valid(board, i, j) || visit[i][j] || board[i][j] != 'O') return;
        visit[i][j] = true;
        cout << i << " " << j << endl;
        markEdges(board, i-1, j);
        markEdges(board, i+1, j);
        markEdges(board, i, j-1);
        markEdges(board, i, j+1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        visit = vector<vector<bool>>(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            markEdges(board, i, 0);
            markEdges(board, i, m-1);
        }

        for(int j=0; j<m; j++){
            markEdges(board, 0, j);
            markEdges(board, n-1, j);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(visit[i][j] == false && board[i][j] == 'O'){
                    region(board, i, j);
                }
            }
        }
    }
};