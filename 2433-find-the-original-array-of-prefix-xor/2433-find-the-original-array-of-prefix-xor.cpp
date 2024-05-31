class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        // int ele = pref[0];
        ans.push_back(pref[0]);

        for(int i=1; i<pref.size(); i++){
            // ele = ele^pref[i];
            ans.push_back((pref[i] ^ pref[i-1]));
            // ele = pref[i];
        }

        return ans;
    }
};