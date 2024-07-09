class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();
        double ans = 0;
        int m = 0;

        for(vector<int> cus : customers){
            cout << m << " ";

            if(m < cus[0]){
                m = cus[0] + cus[1];
                ans += m - cus[0];
            }
            else{
                m += cus[1];
                ans += m - cus[0];
            }
        }

        return ans / n;
    }
};