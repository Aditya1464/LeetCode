class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;

        int i = 0;

        while(i < words.size()){
            
            int j = i;
            int wd = 0;
            while(j < words.size()){
                if(wd + words[j].size() + j - i <= maxWidth){
                    wd += words[j].size();
                    j++;
                }
                else break;
            }

            j--;

            int sp = maxWidth - wd;

            if(j == words.size() - 1){

                if(i == j){
                    string temp;
                    temp += words[j];
                    for(int l = 0; l<sp; l++){
                        temp += ' ';
                    }
                    ans.push_back(temp);
                }
                else{
                    
                    string temp;
                    for(int k=i; k<=j; k++){
                        temp += words[k] + ' ';
                        sp--;
                    }
                    if(sp < 0) temp.pop_back();
                    for(int l = 0; l<sp; l++){
                        temp += ' ';
                    }
                    ans.push_back(temp);
                }
            }
            else{
                int evSp = 0;
                if(i!=j) evSp = sp / (j-i);
                // cout <<sp << " "<< evSp << endl;

                // bool isTrue = true;
                // if(sp % 2 == 0) isTrue = false;

                int cnt = sp - evSp * (j-i);

                string temp;

                for(int k = i; k<j; k++){
                    temp += words[k];

                    for(int l = 0; l<evSp; l++){
                        temp += ' ';
                    }

                    if(cnt){
                        temp += ' ';
                        // isTrue = false;
                        cnt--;
                    }
                } 

                temp += words[j];

                if(i == j){
                    for(int l = 0; l<sp; l++){
                        temp += ' ';
                    }
                }

                ans.push_back(temp);

            }

            i = j+1;
        }

        return ans;
    }
};