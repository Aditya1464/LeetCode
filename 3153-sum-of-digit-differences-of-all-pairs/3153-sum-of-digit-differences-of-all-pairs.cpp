class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int d=0;
        int num = nums[0];
        while(num != 0){
            d++;
            num/=10;
        }
        // cout << d;
        vector<vector<long long>> freq(d, vector<long long>(10, 0));

        for(int i=0; i<n; i++){
            int m = nums[i];
            int k = 0;
            while(m != 0){
                freq[k][m%10]++;
                k++;
                m /= 10;
            }
        }
        long long sum = 0;
        for(int i=0; i<d; i++){

            for(int j=0; j<10; j++){
                if(freq[i][j] != 0){
                    for(int l=j+1; l<10; l++){
                        if(freq[i][l] != 0){
                            sum += (freq[i][j])*freq[i][l];
                        }
                    }
                }
            }
        }

        return sum;
    }
};