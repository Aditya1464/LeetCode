class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        unordered_set<char> set;
        int maxlen = 0;

        while(r < s.size()){
            char ch = s[r];

            if(set.count(ch) == 0){
                set.insert(ch);
            }
            else{
                while(l<r && set.count(ch) == 1){
                    set.erase(s[l]);
                    l++;
                }
                set.insert(ch);
            }

            maxlen = max(maxlen, r-l+1);
            r++;
        }

        return maxlen;
    }
};