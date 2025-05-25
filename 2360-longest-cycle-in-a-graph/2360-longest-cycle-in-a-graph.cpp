class Solution {
private:
    int maxLen = -1;
    void helper(vector<int> & edges, vector<bool> &vis, vector<int>& pathVis, int len, int i){
        vis[i] = 1;
        if(edges[i] == -1) return;
        pathVis[i] = len;

        if(!vis[edges[i]]){
            helper(edges, vis, pathVis, len+1, edges[i]);
        }
        else{
            if(pathVis[edges[i]]){
                maxLen = max(maxLen, len - pathVis[edges[i]] + 1);
            }
        }

        pathVis[i] = 0;
        return;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, 0);
        vector<int> pathVis(n, 0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                helper(edges, vis, pathVis, 1, i);
            }
        }
        return maxLen;
    }
};