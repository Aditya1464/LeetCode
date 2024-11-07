class Solution {
public:
    int largestCombination(vector<int>& cand) {
        int size = cand.size();
        int count = 0;
        int ans = 0;
        int k = 1;
        for(int i = 0; i<32; i++){ 
            count = 0;
            for(int j  = 0; j< size; j++){
                if(k & cand[j]){
                    count++;
                }
            }
            ans = max(ans, count);
            k = k<<1;
        }
        return ans;
    }
};