class Solution {
private:
    void make(string& ans, int& a, char ch){
        int i = 0;
        cout << a << ch << endl;
        while(i<ans.size() && a > 0){
            if(i == 0 && ans[0] != ch){
                if(a >= 1){
                    if(a >= 2){
                        ans = ch + ans;
                        ans = ch + ans;
                        a -= 2;
                        i += 2;
                    }
                    else{
                        ans = ch + ans;
                        a--;
                        i++;
                    }
                }
                continue;
            }

            if(ans[i] == ch){
                if(i+1 >= ans.size()){
                    ans += ch;
                    a--;
                    i += 2;
                }
                else if(i+1 < ans.size() && ans[i+1] == ch){
                    i += 2;
                }
                else{
                    ans = ans.substr(0, i+1) + ch + ans.substr(i+1, ans.size()-i-1);
                    cout << ans << endl;
                    a--;
                    i+=2;
                }
            }
            else{
                if(i+1 >= ans.size()){
                    ans += ch;
                    a--;
                    i += 1;
                }
                else if(i+1 < ans.size() && ans[i+1] != ch){
                    ans = ans.substr(0, i+1) + ch + ans.substr(i + 1, ans.size()-i-1);
                    cout << ans << endl;
                    a--;
                    i += 1;
                }
                else if(i+1 < ans.size() && ans[i+1] == ch){
                    i++;
                }
            }
        }
    }
public:
    string longestDiverseString(int a, int b, int c) {
        
        int minm = min(a,b);
        string add = "";

        if(minm != 0){
            if(c!=0){
                minm = min(minm, c);
                add = "abc";
            }
            else if(c==0){
                add = "ab";
            }
        }
        else if(minm == 0){
            if(a == 0 && b == 0){
                minm = c;
                add += 'c';
            }
            else if(a == 0){
                if(c == 0){
                    minm = b;
                    add += 'b';
                }
                else{
                    minm = min(b,c);
                    add = "bc";
                }
            }
            else if(b == 0){
                if(c==0){
                    minm = a;
                    add += 'a';
                }
                else{
                    minm = min(c, a);
                    add = "ca";
                }
            }
        }

        cout << "add: " << add << endl;

        if(add.size() == 1){
            return add + add;
        }

        string ans;

        for(int i=0; i<minm; i++){
            ans += add;
        }

        if(a != 0) a-=minm;
        if(b != 0) b-=minm;
        if(c != 0) c-=minm;


        cout << ans << endl;

        vector<int> arr;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);

        sort(arr.begin(), arr.end());

        for(int i=0; i<3; i++){
            if(arr[i]==a) make(ans, a, 'a');
            else if(arr[i] == b) make(ans, b, 'b');
            else make(ans, c, 'c');
        }

        if(a!=0) make(ans, a, 'a');
        if(b!=0) make(ans, b, 'b');
        if(c!=0) make(ans, c, 'c');


        return ans;
    }
};