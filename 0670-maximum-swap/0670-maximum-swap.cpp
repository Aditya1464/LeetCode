class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        string temp = str;
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        int i = 0;
        // cout<<temp<<endl;
        for(; i<str.size(); i++){
            if(str[i]!=temp[i]){
                // cout<<i<<endl;
                break;
            }
        }
        char index = temp[i];
        int idx = -1;
        // cout<<"i "<<i<<endl;
        for(int j = str.size()-1; j>=i+1; j--){
            if(index==str[j]){
            idx = j;
            break;
            }
        }
        // cout<<i<<" "<<idx<<endl;
        if(idx != -1)
        swap(str[i], str[idx]);
        return stoi(str);

    }
};