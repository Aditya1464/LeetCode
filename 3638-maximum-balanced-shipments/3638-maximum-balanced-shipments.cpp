class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt = 0;
        int r = 0;
        int maxm = weight[r];
        r++;
        while(r < weight.size()){
            maxm = max(maxm, weight[r]);
            if(maxm != weight[r]){
                cnt++;
                maxm = -1;
            }
            r++;
        }
        return cnt;
    }
};