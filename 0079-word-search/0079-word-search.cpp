class Solution {
public:
    bool isValid(vector<vector<char>>& board, string word, int **visit, int i, int j){
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0) return false;
        if(visit[i][j] == 1) return false;
        if(board[i][j] != word[0]) return false;

        return true;
    }

    bool helper(vector<vector<char>>& board, string word, int**visit, int i, int j){

        if(word.size() == 0){
            return true;
        }

        visit[i][j] = 1;

        bool isTrue = false;

        //right
        if(isValid(board, word, visit, i, j+1)){
            isTrue = helper(board, word.substr(1), visit, i, j+1);
            if(isTrue) return true;
        }

        // left
        if(isValid(board, word, visit, i, j-1)){
            isTrue = helper(board, word.substr(1), visit, i, j-1);
            if(isTrue) return true;
        }

        //up
        if(isValid(board, word, visit, i-1, j)){
            isTrue = helper(board, word.substr(1), visit, i-1, j);
            if(isTrue) return true;
        }

        // down
        if(isValid(board, word, visit, i+1, j)){
            isTrue = helper(board, word.substr(1), visit, i+1, j);
            if(isTrue) return true;
        }

        visit[i][j] = 0;
        return isTrue;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int **visit = new int*[board.size()];
        for(int i=0; i<board.size(); i++){

            visit[i] = new int[board[i].size()];

            for(int j=0; j<board[i].size(); j++){
                visit[i][j] = 0;
            }
        }

        bool isTrue = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0]){
                    isTrue = helper(board, word.substr(1), visit, i, j);
                }

                if(isTrue) return true;
            }
        }

        return isTrue;
    }
};