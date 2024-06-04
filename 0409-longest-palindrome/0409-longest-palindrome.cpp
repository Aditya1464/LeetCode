class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;

        for(int i=0; i<s.size(); i++) map[s[i]]++;

        int totalEven = 0;
        int totalOdd = 0;
        int maxOdd = 0;

        for(int i=0; i<s.size(); i++){
            if(map[s[i]] != 0){

                if(map[s[i]] % 2 == 0) totalEven += map[s[i]];
                else{
                    totalOdd += map[s[i]] - 1;
                    if(maxOdd < map[s[i]]) maxOdd = map[s[i]];
                }
                
                map[s[i]] = 0;
            }
        }

        int ans = totalEven + totalOdd;
        if(maxOdd != 0) ans++;

        return ans;
    }
};