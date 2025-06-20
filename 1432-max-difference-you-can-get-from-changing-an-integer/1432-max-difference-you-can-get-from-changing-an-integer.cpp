class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = to_string(num);

        char ch;
        for(int i=0; i<str1.size(); i++){
            if(str1[i] != '9') {
                ch = str1[i];
                str1[i] = '9';
                i++;
                while(i < str1.size()){
                    if(str1[i] == ch) str1[i] = '9';
                    i++;
                }
                break;
            }
        }
        unordered_set<char> set;
        for(int i=0; i<str2.size(); i++){  
            if(set.count(str2[i]) == 1) continue;  
            char k = '1';
            if(i != 0) k = '0';
            if(str2[i] != k) {
                ch = str2[i];
                str2[i] = k;
                i++;
                while(i < str2.size()){
                    if(str2[i] == ch) str2[i] = k;
                    i++;
                }
                break;
            }
            set.insert(str2[i]);
        }

        return stoi(str1) - stoi(str2);
    }
};