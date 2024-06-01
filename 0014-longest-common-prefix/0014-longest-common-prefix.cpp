#include<bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        
        int n = strs[0].size();

        for(int i=1; i<strs.size(); i++){
            // n = min(n, strs[i].size());
            if(n > strs[i].size()) n = strs[i].size();

            int m = 0;
            for(int j=0; j<n; j++){
                if(strs[i][j] == strs[i-1][j]) m++;
                else break;
            }

            n = m;

            if(n==0) break;
        }

        return strs[0].substr(0, n);
    }
};