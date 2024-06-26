class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1, n = digits.size();
        vector<int> ans;

        for(int i = n-1; i>=0; i--){
            int sum = carry + digits[i];
            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        if(carry) ans.push_back(carry);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};