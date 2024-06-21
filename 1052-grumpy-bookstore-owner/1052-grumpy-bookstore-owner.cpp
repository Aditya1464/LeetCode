class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int ans = 0;
        int n = grumpy.size();
        
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0) ans += customers[i];
        }

        int max = ans;

        for(int i=0; i<=(n-minutes); i++){

            int temp = ans;

            for(int j=i; j<(i+minutes); j++){
                if(grumpy[j] == 1) temp += customers[j];
            }

            if(max < temp) max = temp;
        }

        return max;
    }
};