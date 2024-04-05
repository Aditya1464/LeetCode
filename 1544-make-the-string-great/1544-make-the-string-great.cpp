class Solution {
public:
    string makeGood(string s) {        
        int i=0;
        while(i < s.size()){
            if(i > s.size()-2) break;
            if(s[i] == s[i+1] + 32 || s[i] + 32 == s[i+1]){
                s.erase(i, 2);
                if(i==0) i = 0;
                else i--;
                continue;
            }
            i++;
        }
        return s;
    }
};