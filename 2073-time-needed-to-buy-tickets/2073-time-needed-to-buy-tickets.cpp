class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        // queue<int> q;
        // for(int i=0; i<tickets.size(); i++){
        //     q.push(tickets[i]);
        // }

        // int ans = 0;

        // while(!q.empty()){

        //     int top = q.front();
        //     top--;
        //     ans++;

        //     if(k == 0 && top == 0){
        //         return ans;
        //     }

        //     q.pop();
        //     if(top != 0) q.push(top);
            
        //     if(k == 0) k = q.size() - 1;
        //     else k--;
        // }

        // return ans;



        int ans = 0;
        while(tickets.size() != 0){
            int top = tickets[0];
            tickets.erase(tickets.begin());
            top--;
            ans++;

            if(k==0 && top == 0){
                return ans;
            }

            if(top != 0) tickets.push_back(top);

            if(k == 0) k = tickets.size() - 1;
            else k--;
        }

        return ans;
    }
};