class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, i = 0;
        while(tickets.size() != 0){
            if(tickets[i] == -1){
                i++;
                if(i == tickets.size()) i = 0;
                continue;
            }

            int top = tickets[i];
            top--;
            ans++;

            if(k==i && top == 0){
                return ans;
            }

            if(top != 0){
                tickets[i] = top;
            }
            else{
                tickets[i] = -1;
            }

            i++;
            if(i == tickets.size()) i = 0;
        }

        return ans;
    }
};