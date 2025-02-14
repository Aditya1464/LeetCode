class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        int ans = 0;

        while(minHeap.top() < k){
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();

            x = min(x, y) * 2 + max(x, y);
            ans++;
            minHeap.push(x);
        }

        return ans;
    }
};