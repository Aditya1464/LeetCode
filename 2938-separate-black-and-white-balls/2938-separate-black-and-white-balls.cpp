class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long count = 0;

        for(auto ch : s){
            if(ch == '1'){
                count++;
            }
            else{
                if(count){
                    ans += count;
                }
            }
        }

        return ans;
    }
};