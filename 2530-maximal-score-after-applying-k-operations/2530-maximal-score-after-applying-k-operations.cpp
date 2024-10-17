class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        // sort(nums.begin(), nums.end());
        priority_queue<int> heap(nums.begin(), nums.end());
        double val;
        for(int i = 0; i<k; i++){
            val = heap.top();
            score += val;
            heap.pop();
            heap.push(ceil(val/3));
        }
        return score;
    }
};