class Solution {
public:

    int minimumLength(string s) {
        
        int sp = 0;
        int ep = s.size()-1;
        

        while(sp < ep){
            if(s[sp] != s[ep]) break;
            
            if(s[sp] == s[sp+1]){
                sp++;
                if(sp == ep) return 0;
            }
            
            else if(s[ep] == s[ep-1]){
                ep--;
                if(sp == ep) return 0;
            }

            else{
                sp++;
                ep--;
            }
        }

        return (ep-sp+1);
    }
};