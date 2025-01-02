class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> temp(words.size(), 0);
        vector<bool> IsTrue(words.size(), 0);

        int val = 0;
        for(int i=0; i<words.size(); i++){
            int t = words[i].size() - 1;
            if((words[i][0]=='a' || words[i][0] =='e' || words[i][0] =='i' || words[i][0] == 'o' || words[i][0] == 'u') && (words[i][t]=='a' || words[i][t] =='e' || words[i][t] =='i' || words[i][t] == 'o' || words[i][t] == 'u') ) {
                val++;
                IsTrue[i] = true;
            }

            temp[i] = val;
        }

        vector<int> ans(queries.size(), 0);

        for(int i=0; i<queries.size(); i++){
            int k = queries[i][0];
            int l = queries[i][1];
            ans[i] = temp[l] - temp[k];
            if(IsTrue[k]) ans[i]++;
        }

        return ans;
    }
};