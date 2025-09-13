class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for(auto& c: s){
            freq[c-'a']++;
        }

        int cnt1 = 0, cnt2 = 0;
        for(int i=0; i<26; i++){
            char c = i + 'a';
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                cnt1 = max(cnt1, freq[i]);
            }
            else cnt2 = max(cnt2, freq[i]);
        }
        return cnt1+cnt2;
    }
};