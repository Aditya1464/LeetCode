class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> map;

        if(s.size() != t.size()) return 0;

        for(int i=0; i<s.size(); i++){
            map[s[i]] ++;
            map[t[i]] --;
        }

        for(int i=0; i<s.size(); i++){
            if(map[s[i]] != 0) return 0;
        }
        
        return 1;
    }
};