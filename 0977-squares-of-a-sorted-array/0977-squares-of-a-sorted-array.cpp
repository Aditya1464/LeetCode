class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<nums.size(); i++){
            int n = nums[i] * nums[i];
            pq.push(n);
        }

        for(int i=0; i<nums.size(); i++){
            nums[i] = pq.top();
            pq.pop();
        }

        return nums;
    }
};