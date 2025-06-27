class Solution {
    vector<string> ans;
    void helper(int m, int n, string str){
        if(m == 0 && n == 0){
            ans.push_back(str);
            return;
        }
        if(m != 0){
            str.push_back('(');
            helper(m-1, n, str);
            str.pop_back();
        }

        if(n != 0){
            if(n-1 < m) return;
            str.push_back(')');
            helper(m, n-1, str);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "(";
        helper(n-1, n, str);
        return ans;   
    }
};