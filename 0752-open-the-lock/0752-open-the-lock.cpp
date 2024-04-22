class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if(deadendSet.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");

        while(q.size() != 0){
            auto front = q.front();
            string str = front.first;
            int moves = front.second;
            q.pop();

            if(str == target) return moves;

            for(int i=0; i<4; i++){

                for(int j = -1; j<= 1; j+=2){
                    string temp = str;
                    char ch = temp[i];
                    
                    ch = (ch -'0' + j + 10) % 10 + '0';
                    temp[i] = ch;
                    
                    if (visited.find(temp) == visited.end() && deadendSet.find(temp) == deadendSet.end()) {
                        visited.insert(temp);
                        q.push({temp, moves + 1});
                    }
                }
            }
        }

        return -1;
    }
};