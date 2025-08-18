class Solution {
public:
    int myAtoi(string s) {
        int num = 0, n = s.size();
        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }

        if(i >= n) return 0;

        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            sign = 1;
            i++;
        }
        else if((97 <= s[i] && s[i] <= 122) || (65 <= s[i] && s[i] <= 90)) return 0; 
        while(i < n && s[i] == '0') i++;

        if(i >= n) return 0; 

        if((97 <= s[i] && s[i] <= 122) || (65 <= s[i] && s[i] <= 90) || s[i] == ' ' || s[i] == '-' || s[i] == '+') 
            return 0;

        while(i < n) {
            if((97 <= s[i] && s[i] <= 122) || (65 <= s[i] && s[i] <= 90) || s[i] == ' ' || s[i] == '-' || s[i] == '+') break;
            if(!isdigit(s[i])) break; 

            int digit = s[i] - '0';

            if (num > (INT_MAX - digit) / 10) 
                return sign == 1 ? INT_MAX : INT_MIN;

            num = num * 10 + digit;
            i++;
        }

        return num * sign;
    }
};
