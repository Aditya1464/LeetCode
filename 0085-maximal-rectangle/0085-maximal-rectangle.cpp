class Solution {
public:

    bool isTrue = false;

    bool isValid(vector<vector<char>>& matrix, int i, int j){
        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size() && matrix[i][j] == '1';
    }

    int helper(vector<vector<char>>& matrix, int i, int j){
        if(!isValid(matrix, i+1, j) && !isValid(matrix, i, j+1) && !isValid(matrix, i+1, j+1))
        return 1;

        int ans1 = 0, ans2 = 0, ans3 = 0;

        if(isValid(matrix, i+1, j) && isValid(matrix, i, j+1) && isValid(matrix, i+1, j+1)){      

            int n = 0, m = 0;

            int count = 0;
            int q = i;

            for(int k = i; k < matrix.size(); k++){
                if(matrix[k][j] == '0') break;
                q = k;
                count ++;
            }

            n++;

            int p = 0;

            for(int l = j + 1; l < matrix[0].size(); l++){

                int count2 = 0;

                for(int k = i; k <= q; k++){
                    if(matrix[k][l] == '0') break;
                    if(l == matrix.size() && k == matrix[0].size()) isTrue = true;
                    count2++;
                }

                q = q - (count - count2);

                if(count2 != count){
                    if(count2 >= 2){
                        if(n*count > p) p = n*count;
                        count = count2;
                    }
                    else break;
                }
                n++;
            }

            if(n*count > p) p = n*count;

            ans1 = p;
        }

        if(isValid(matrix, i+1, j)){
            for(int k = i; k < matrix.size(); k++){
                if(matrix[k][j] == '0') break;
                if(k == matrix.size() && j == matrix[0].size()) isTrue = true;
                ans2++;
            }
        }

        if(isValid(matrix, i, j+1)){
            for(int k = j; k < matrix[i].size(); k++){
                if(matrix[i][k] == '0') break;
                if(i == matrix.size() && k == matrix[0].size()) isTrue = true;
                ans3++;
            }
        }

        int ans = max(ans1, max(ans2, ans3));
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int ans = 0;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){

                if(matrix[i][j] == '1'){
                    int m = helper(matrix, i, j);
                    if(ans < m) ans = m;
                }
                if(isTrue) break;
            }

            if(isTrue) break;
        }
        return ans;
    }
};