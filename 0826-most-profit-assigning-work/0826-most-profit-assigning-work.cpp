class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int ans = 0; //max profit

        for(int i=0; i<worker.size(); i++){ //iterate all the workers

            int prof = 0;
            for(int j=0; j<difficulty.size(); j++){
                if(difficulty[j] <= worker[i] && profit[j] > prof){
                    prof = profit[j];
                }
            }

            ans += prof;
        }

        return ans;
    }
};