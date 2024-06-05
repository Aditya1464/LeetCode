class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // unordered_map<char, pair<int, int>> map;

        // // cout << map['a'].first << " " << map['a'].second;

        // for(int i=0; i<words.size(); i++){
            
        //     for(int j=0; j<words[i].size(); j++){

        //         map[words[i][j]].first = i+1;
        //         map[words[i][j]].second++;
        //     }
        //     cout << map['l'].first << " " << map['l'].second << endl;
        // }

        // vector<string> ans;

        // for(int i=0; i<words[0].size(); i++){

        //     if(map[words[0][i]].first == 3){

                
        //     }
        // }


        vector<int> temp(26,0);

        for(int j=0; j<words[0].size(); j++){
            temp[words[0][j]-'a']++; 
        }

        for(int i=1; i<words.size(); i++){
            unordered_map<char, int> map;
            
            for(int j=0; j<words[i].size(); j++){
                map[words[i][j]]++;
            }

            for(int j=0; j<26; j++){
                temp[j] = min(temp[j], map[j+'a']);
            }
        }


        vector<string> ans;

        for(int i=0; i<26; i++){
            while(temp[i]--){
                string str;
                str.push_back(i + 'a');
                ans.push_back(str);
            }
        }

        return ans;
    }
};