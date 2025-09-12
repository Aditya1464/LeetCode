class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(char &c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                cnt++;
            }
        }

        if(cnt % 2 != 0) return true;
        if(cnt == 0) return false;

        return true;
    }
};