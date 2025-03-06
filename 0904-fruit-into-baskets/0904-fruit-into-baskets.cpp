class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int b1 = -1, b2 = -1, c1 = 0, c2 = 0, l=0, r=0, maxTree = 0;

        while(r<fruits.size()){
            
            if(b1 == -1){
                b1 = fruits[r];
                c1++;
            }
            else if(fruits[r] == b1){
                c1++;
            }
            else if(b2 == -1){
                b2 = fruits[r];
                c2++;
            }
            else if(fruits[r] == b2){
                c2++;
            }
            else{

                while(c1 != 0 && c2 != 0){
                    if(b1 == fruits[l]) c1--;
                    else if(b2 == fruits[l]) c2--;
                    l++;
                }

                if(c1 == 0){
                    b1 = fruits[r];
                    c1++;
                }
                else if(c2 == 0){
                    b2 = fruits[r];
                    c2++;
                }
            }

            maxTree = max(r-l+1, maxTree);
            r++;
        }

        return maxTree;
    }
};