class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i=0;
        while(i < n && height[i] == 0) i++;
        if(i >= n) return 0;
        int ref = height[i];
        i++;
        int ans = 0;
        int temp = 0;

        while(i<n){
            if(height[i] >= ref){
                // cout << temp << " " << height[i] << endl;
                ans += temp;
                ref = height[i];
                temp = 0;
            }
            else temp += ref - height[i];
            i++;
        } 

        i = n-1;
        while(i >= 1 && height[i] < height[i-1]) i--;
        if(i <= 0) return ans;
        int ref2 = height[i];
        // i--;
        temp = 0;
        while(i > 0 && height[i] != ref){
            if(height[i] <= ref2){
                temp += ref2 - height[i];
            }
            else ref2 = height[i];
            i--;
        }

        ans += temp;

        return ans;
    }
};