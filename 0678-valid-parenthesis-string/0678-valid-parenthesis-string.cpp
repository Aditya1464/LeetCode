class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> st;

        int i=0;
        while(i<s.size()){
            
            if(s[i] == '('){
                st.push(i);
                i++;
                continue;
            } 
            if(s[i] == ')' && st.size() != 0){
                s.erase(st.top(),1);
                st.pop();
                s.erase(i-1, 1);
                i--;
                continue;
            }
            i++;
        }

        cout << s << " ";
        if(s.size() == 0) return true;
        
        while(st.size() != 0) st.pop();
        
        i = 0;
        int m = 0;
        while(i < s.size()){
            if(s[i] == '(') m++;

            if(s[i] == '*'){
                st.push(i);
                i++;
                continue;
            }
            if(s[i] == ')'){
                if(st.size() == 0) return false;
                s.erase(st.top(), 1);
                st.pop();
                s.erase(i-1, 1);
                i--;
                continue;
            }
            i++;
        }

        if(m==0) return true;

        cout << s;
        // while(st.size() != 0) st.pop();

        i = s.size() - 1;
        m = 0;
        while(i >= 0){

            if(s[i] == '('){
                if(m == 0) return false;
                m--;
            }
            else m++;
            i--;
        }

        return true;
    }
};








// class Solution {
// public:
//     bool helper(string s, int idx, int count){
//         if(idx == s.size()){
//             if(count == 0) return true;
//             else return false;
//         }

//         if(s[idx] == '('){
//             return helper(s, idx+1, count + 1);
//         }
//         else if(s[idx] == ')'){
//             return helper(s, idx+1, count - 1);
//         }
//         else{
//             if(count == 0) return helper(s, idx+1, count);
//             // return helper(s, idx+1, count) || helper(s, idx+1, count+1) || helper(s, idx+1, count-1);
//             if(helper(s, idx+1, count)) return true;
//             if(helper(s, idx+1, count+1)) return true;
//             if(helper(s, idx+1, count-1)) return true;
//         }

//         return false;
//     }

//     bool checkValidString(string s) {
//         return helper(s, 0, 0);
//     }
// };















// class Solution {
// public:
//     bool checkValidString(string s) {
        
//         int count = 0;
//         bool isStar = false;
//         int cStar = 0;

//         for(int i=0; i<s.size(); i++){
//             if(count == 0 && s[i] == ')'){
//                 if(isStar){
//                     isStar = false;
//                     continue;
//                 }
//                 else return false;
//             }

//             if(s[i] == '('){
//                 count++;
//                 continue;
//             }

//             if(s[i] == '*'){
//                 if(count != 0) cStar ++;
//                 isStar = true;
//                 continue;
//             }

//             if(s[i] == ')'){
//                 count--;
//             }
//         }

//         cout << count << " " << cStar;

//         if(cStar >= count) return true;

//         return false;
//     }
// };