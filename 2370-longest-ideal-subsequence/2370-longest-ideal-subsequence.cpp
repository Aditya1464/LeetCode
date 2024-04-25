class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> arr(n);

        arr[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            char ch = s[i];
            int max = 0;
            for(int j = i+1; j < n; j++){
                if(abs(ch - s[j]) <= k){
                    if(max < arr[j]){
                        max = arr[j];
                    }
                }
            }

            arr[i] = max + 1;
        }

        int ans = arr[0];
        for(int i=1; i<n; i++){
            if(ans < arr[i]) ans = arr[i];
        }
        return ans;
    }
};











// class Solution {
// public:
//     int helper(string s, int k, int i, char ch){
//         if(i == s.size()) return 0;

//         if(abs(ch - s[i]) <= k){

//             int ans1 = helper(s, k, i+1, ch);
//             int ans2 = 1 + helper(s, k, i+1, s[i]);

//             return max(ans1, ans2);
//         }
//         else return helper(s, k, i+1, ch);
//     }

//     int longestIdealString(string s, int k) {

//         int ans = 0;

//         for(int i=0; i<s.size(); i++){
//             int temp = helper(s, k, i+1, s[i]);
//             if(ans < temp){
//                 ans = temp;
//             }

//             if(ans >= s.size() - i) break;
//         }

//         return ans+1;
//     }
// };