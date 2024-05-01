class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int i=0;
        int j=0;

        for(int k=0; k<word.size(); k++){
            j++;
            if(word[k] == ch) break;
        }

        if(j==0) return word;
        if(j==word.size() && word[j-1] != ch) return word;
        j--;

        while(i<j){
            char c = word[i];
            word[i] = word[j];
            word[j] = c;
            i++;
            j--;
        }

        return word;
    }
};