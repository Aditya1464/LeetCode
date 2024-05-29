class Solution {
public:
    void incrementby1(string& s){
        char ch = '1';
        for(int i=s.size()-1; i>=0; i--){

            if(ch == '1' && s[i] == '0'){
                s[i] = ch;
                return;
            }
            else if(ch == '1' && s[i] == '1'){
                s[i] = '0';
            }
        }

        if(ch == '1'){
            reverse(s.begin(), s.end());
            s.push_back(ch);
            reverse(s.begin(), s.end());
        }
    }

    int numSteps(string s) {
        
        int ans = 0;
        while(s.size() != 1){
            if(s[s.size()-1] == '1'){
                incrementby1(s);
            }
            else{
                s.pop_back();
            }
            // cout << s << " ";
            ans++;
        }
        return ans;
    }
};