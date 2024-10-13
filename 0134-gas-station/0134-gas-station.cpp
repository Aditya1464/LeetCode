class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        if(n == 1){
            if(gas[0] >= cost[0]) return 0;
            return -1;
        }

        for(int i=0; i<n; i++){

            if(gas[i] > cost[i]){
                
                int tank = gas[i];
                int j = 0;

                for(; j < n-1; j++){
                    int k = j+i;
                    int l = j+i+1;
                    if(k >= n) k = k % n;
                    if(l >= n) l = l % n;

                    if(tank <= cost[k]) break;

                    tank = tank - cost[k] + gas[l];
                }

                if(j != n-1) continue;

                int k = i-1;
                if(k<0) k = n-1;

                if(tank >= cost[k]) return i;        
            }
        }

        return -1;
    }
};