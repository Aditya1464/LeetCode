class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> map1, map2;

        if(s.size() != t.size()) return false;

        for(int i=0; i<s.size(); i++){

            if(map1.count(t[i]) || map2.count(s[i])){
                if(map1[t[i]] != s[i]) return false;
                if(map2[s[i]] != t[i]) return false;
            }
            else{
                map1[t[i]] = s[i];
                map2[s[i]] = t[i];
            }
        }

        return true;
    }
};