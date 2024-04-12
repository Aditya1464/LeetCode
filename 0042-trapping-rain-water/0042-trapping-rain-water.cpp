class Solution {
public:
    int helper(vector<int> height, int i, int j){
        int k = min(height[i], height[j]);
        int ans = 0;

        for(int m = i + 1; m < j; m++){
            ans += k - height[m];
        }
        return ans;
    }

    int trap(vector<int>& height) {
        
        int i = 0;
        int j = height.size() - 1;

        while(i+1 < height.size() && height[i+1] >= height[i]){
            i++;
        }

        while(j-1 >= 0 && height[j-1] >= height[j]){
            j--;
        }

        cout << i << " " << j << endl;

        int secIdx = i + 1;
        int k = i + 1;
        int ans = 0;

        while(i < j && k <= j){

            if(height[k] >= height[i]){
                ans += helper(height, i, k);
                cout << ans << " " << "t" << " ";
                i = k;
                k = i + 1;
                secIdx = k;
            }
            else{

                if(height[secIdx] <= height[k]){
                    secIdx = k;
                }
                k++;
            }

            if(k > j && height[k-1] < height[i]){
                ans += helper(height, i, secIdx);
                cout << ans << " " << "t" << " ";
                i = secIdx;
                k = i + 1;
                secIdx = k;
            }
        }

        return ans;
    }
};