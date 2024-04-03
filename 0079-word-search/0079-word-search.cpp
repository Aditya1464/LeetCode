class Solution {
public:
    bool isValid(vector<vector<char>>& board, string word, vector<vector<bool>>& visit, int i, int j, int idx){
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && !visit[i][j] && board[i][j] == word[idx];
    }

    bool helper(vector<vector<char>>& board, string word,vector<vector<bool>>& visit, int i, int j, int idx){

        if(word.size() == idx){
            return true;
        }

        if(!isValid(board, word, visit, i, j, idx)) return false;

        visit[i][j] = true;

        bool isTrue = helper(board, word, visit, i, j+1, idx+1) ||
                      helper(board, word, visit, i, j-1, idx+1) ||
                      helper(board, word, visit, i-1, j, idx+1) ||
                      helper(board, word, visit, i+1, j, idx+1);

        visit[i][j] = false;
        return isTrue;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0] && helper(board, word, visit, i, j, 0)){
                    return true;
                }

            }
        }

        return false;
    }
};