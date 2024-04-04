class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;

        for(int i=0; i<s.size(); i++){

            if(s[i] == '('){
                st.push('(');
            }
            else if(s[i] == ')'){
                if(ans < st.size()) ans = st.size();
                st.pop();
            }
        }

        return ans;
    }
};