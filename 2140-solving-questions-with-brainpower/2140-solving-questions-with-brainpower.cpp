class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> temp(questions.size(), 0);
        vector<long long> maxm(questions.size(), 0);
        long long ans = 0;
        long long temp2 = 0;

        for(int i=questions.size()-1; i>=0; i--){
            temp[i] = questions[i][0];
            int j = i + questions[i][1] + 1;
            if(j < questions.size()) temp[i] += maxm[j];
            temp2 = max(temp2, temp[i]);
            maxm[i] = temp2;
            ans = max(ans, temp[i]);
        }
        return ans;
    }
}; 