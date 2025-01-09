class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int s = pref.size();
        int ans = 0;

        for(int i=0; i<words.size(); i++){
            if(s <= words[i].size()){
                if(words[i].substr(0, s) == pref) {
                    ans++;
                }
            }
        }

        return ans;
    }
};