class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;

        for(int i=0; i<s.size(); ){
            if(st.size() == 0 && s[i] == ')'){
                s.erase(i, 1);
                continue;
            }

            if(s[i] == '('){
                st.push(i);
            }

            if(s[i] == ')'){
                st.pop();
            }
            i++;
        }

        while(st.size() != 0){
            s.erase(st.top(), 1);
            st.pop();
        }

        return s;
    }
};