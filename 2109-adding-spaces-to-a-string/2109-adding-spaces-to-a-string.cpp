class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        string ans = "";
        int j = 0;
        for(int i=0; i<spaces.size(); i++){
            ans += s.substr(j, spaces[i] - j) + " ";
            j = spaces[i];
        }
        ans += s.substr(j, s.size() - j);
        return ans;
    }
};