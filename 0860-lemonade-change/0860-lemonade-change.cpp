class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int no_5 = 0, no_10 = 0, no_20 = 0;

        for(auto it: bills){
            if(it == 5){
                no_5++;
            }
            else if(it == 10){
                no_10++;
                if(no_5 <= 0) return false;
                no_5--;
            }
            else {
                no_20++;

                if(no_10 <= 0){
                    if(no_5 <= 2) return false;
                    no_5 -= 3;
                }
                else{
                    if(no_5 <= 0) return false;
                    no_5--;
                    no_10--;
                }
            }
        }

        return true;
    }
};