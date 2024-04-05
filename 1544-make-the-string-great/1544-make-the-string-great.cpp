class Solution {
public:

    void helper(string& s, int i){
        if(i == s.size()) return;
        if(i > s.size() - 2) return;

        if(s[i] == s[i+1] + 32 || s[i] + 32 == s[i+1]){
            s.erase(i, 2);
            helper(s, 0);
            return;
        }

        helper(s, i+1);
        return;
    }

    string makeGood(string s) {
        
        helper(s, 0);
        return s;
    }
};