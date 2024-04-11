class Solution {
public:

    // bool cmp(string num, string ans){

    //     unsigned long long num1 = 0;
    //     unsigned long long ans1 = 0;
    //     int i = 0;
    //     while(i < num.size()){
    //         num1 = num1*10 + (num[i] - '0');
    //         i++;
    //     }

    //     i = 0;
    //     while(i < ans.size()){
    //         ans1 = ans1*10 + (ans[i] - '0');
    //         i++;
    //     }

    //     return (num1 < ans1);
    // }

    // void helper(string num, string &ans, int k, int i){
    //     if(i == num.size() && k != 0) return;

    //     if(k==0){
    //         bool is = cmp(num ,ans);
    //         if(is) ans = num;
    //         return;
    //     }
    //     helper(num.substr(0, i) + num.substr(i+1), ans, k-1, i);
    //     helper(num, ans, k, i+1);
    // }

    string removeKdigits(string num, int k) {
        // string ans = num;
        // helper(num, ans, k, 0);

        // while(ans.size() != 0 && ans[0] == '0'){
        //     ans = ans.substr(1);
        // }

        // if(ans.size() == 0){
        //     ans.push_back('0');
        // }

        // return ans;


        stack<char> st;
        st.push(num[0]);

        for(int i=1; i<num.size(); i++){

            while(st.size() > 0 && k > 0 && st.top() > num[i]){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(k--){
            st.pop();
        }

        num.clear();

        while(st.size() != 0){
            num.push_back(st.top());
            st.pop();
        }

        reverse(num.begin(), num.end());

        while(num.size() != 0 && num[0] == '0'){
            num = num.substr(1);
        }

        if(num.size() == 0) num.push_back('0');

        return num;
    }
};