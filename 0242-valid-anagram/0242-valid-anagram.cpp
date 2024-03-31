class Solution {
public:
    bool isAnagram(string s, string t) {

        // unordered_map<char, int> map;

        // if(s.size() != t.size()) return 0;

        // for(int i=0; i<s.size(); i++){
        //     map[s[i]] ++;
        //     map[t[i]] --;
        // }

        // for(auto each : s){
        //     if(map[each] != 0) return 0;
        // }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s==t;
    }
};