class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> map;

        int left = 0, right = 0, count = 0, n = s.size();

        while(right < n){

            map[s[right]] ++;
            
            while(map[s[right]] > 1){
                map[s[left++]]--;
            }

            count = max(count, right-left+1);
            right++; 
        }

        return count;
    }
};