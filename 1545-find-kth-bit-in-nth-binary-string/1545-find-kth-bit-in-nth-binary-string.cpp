class Solution {
public:
    string helper2(string str){
        for(int i=0; i<str.size(); i++){
            if(str[i] == '0') str[i] = '1';
            else str[i] = '0';
        }

        reverse(str.begin(), str.end());
        return str;
    }

    string helper(int n){
        if(n == 1) return "0";

        string str = helper(n-1);
        string temp = helper2(str);
        str = str + "1" + temp;
        return str;
    }

    char findKthBit(int n, int k) {
        string str = helper(n);
        return str[k-1];
    }
};