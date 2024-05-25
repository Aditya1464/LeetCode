class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int, int> map;
        unordered_map<int, int> set;
        int n = 0;
        vector<int> ans;

        for(int i=0; i<queries.size(); i++){
            int x = queries[i][0];
            int y = queries[i][1];

            if(map.count(x) == 0){
                map[x] = y;
                if(set[y] == 0){
                    n++;
                    ans.push_back(n);
                    set[y]++;
                }
                else{
                    set[y]++;
                    ans.push_back(n);
                }
            }
            else{
                if(set[map[x]] != 0){
                    set[map[x]]--;
                    if(set[map[x]] == 0) n--;
                }

                map[x] = y;
                if(set[y] == 0){
                    n++;
                    ans.push_back(n);
                    set[y]++;
                }
                else{
                    set[y]++;
                    ans.push_back(n);
                }
            }
        }

        return ans;
    }
};