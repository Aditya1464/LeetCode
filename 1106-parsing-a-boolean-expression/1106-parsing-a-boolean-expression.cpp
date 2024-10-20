class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(int i=0; i<expression.size(); i++){
            if(expression[i] != ')'){
                st.push(expression[i]);
            }
            else{
                char top = st.top();
                vector<char> exp;
                while(top != '('){
                    if(top != ',') exp.push_back(top);
                    st.pop();
                    top = st.top();
                }

                st.pop();
                top = st.top();
                st.pop();

                if(top == '!'){
                    if(exp[0] == 'f') st.push('t');
                    else st.push('f');
                }
                else if(top == '&'){
                    char ch = exp[0];
                    for(int i=1; i<exp.size(); i++){
                        if(ch == 't' && exp[i] == 't') ch = 't';
                        else ch = 'f';
                    }
                    st.push(ch);
                }
                else{
                    char ch = exp[0];
                    for(int i=1; i<exp.size(); i++){
                        if(ch == 'f' && exp[i] == 'f') ch = 'f';
                        else ch = 't';
                    }
                    st.push(ch);
                }
            }
        }

        if(st.top() == 'f') return false;
        return true;
    }
};