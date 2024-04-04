class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        // stack<char> st;
        int count = 0;

        for(int i=0; i<s.size(); i++){

            if(s[i] == '('){
                // st.push('(');
                count++;
            }
            else if(s[i] == ')'){
                if(ans < count) ans = count;
                count--;
            }
        }

        return ans;
    }
};