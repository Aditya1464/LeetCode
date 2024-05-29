class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // string str1 = "Gold Medal";
        // string str2 = "Silver Medal";
        // string str3 = "Bronze Medal";
        vector<string> ans;

        priority_queue<int> q;
        q = priority_queue<int>(score.begin(), score.end());

        unordered_map<int, int> map;
        for(int i=0; i<score.size(); i++){
            map[q.top()] = i+1;
            q.pop();
        }

        for(int i=0; i<score.size(); i++){

            if(map[score[i]] == 1) ans.push_back("Gold Medal");
            else if(map[score[i]] == 2) ans.push_back("Silver Medal");
            else if(map[score[i]] == 3) ans.push_back("Bronze Medal");
            else {
                ans.push_back(to_string(map[score[i]]));
            }
        }

        return ans;
    }
};