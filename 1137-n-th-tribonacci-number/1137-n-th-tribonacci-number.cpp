class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;

        int ans1 = 0;
        int ans2 = 1;
        int ans3 = 1;

        for(int i = 3; i<=n; i++){
            int temp = ans3;
            ans3 = ans1 + ans2 + ans3;
            ans1 = ans2;
            ans2 = temp;
        }

        return ans3;
    }
};