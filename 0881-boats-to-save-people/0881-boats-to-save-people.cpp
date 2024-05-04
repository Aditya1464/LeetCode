class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());

        int i=0, j=people.size()-1;
        int ans = 0;

        while(i <= j){

            if(people[j] == limit){
                ans++;
                j--;
            }
            else if(people[j] < limit){

                if(people[j] + people[i] <= limit){
                    ans++;
                    i++;
                    j--;
                }
                else{
                    ans++;
                    j--;
                }
            }
        }

        return ans;
    }
};