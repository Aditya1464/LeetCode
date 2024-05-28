class Solution {
public:
    // int temp = 0;
    // int ans = 0;
    // int tempCount = 0;

    // void helper(vector<int>& d, int& maxCost, int idx){
    //     if(idx == d.size()){
    //         if(temp <= maxCost) ans = max(ans, tempCount);
    //         return;
    //     }

    //     if(temp + d[idx] <= maxCost){
    //         temp += d[idx];
    //         tempCount ++;
    //         helper(d, maxCost, idx+1);
    //     }
    //     else{
    //         ans = max(ans, tempCount);
    //     }

    //     temp = 0;
    //     tempCount = 0;
    //     helper(d, maxCost, idx+1);
    // }

    int equalSubstring(string s, string t, int maxCost) {
        vector<int> d(s.size());
        for(int i=0; i<s.size(); i++){
            d[i] = abs(s[i] - t[i]);
        }

        // helper(d, maxCost, 0);
        // return ans;

        int i=0, j=0;
        int temp = 0, maxCount = 0, tempCount = 0;

        while(i < d.size()){
            temp += d[i];
            tempCount++;

                while(temp > maxCost){
                    temp -= d[j];
                    tempCount--;
                    j++;
                }

            i++;
            maxCount = max(tempCount, maxCount);
        }

        return maxCount;
    }
};