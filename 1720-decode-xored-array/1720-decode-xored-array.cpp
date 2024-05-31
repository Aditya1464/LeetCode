class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
        vector<int> arr;
        arr.push_back(first);

        for(int i=0; i<encoded.size(); i++){
            first = first ^ encoded[i];
            arr.push_back(first);
        }

        return arr;
    }
};