class Solution {
private:
    vector<bool> vis;
    void helper(int node, vector<int>& edges, vector<int> &v, int dist){
        vis[node] = 1;
        v[node] = dist;
        if(edges[node] != -1 && !vis[edges[node]]) helper(edges[node], edges, v, dist+1);
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> v1(n, -1);
        vector<int> v2(n, -1);
        vis.assign(n, 0);
        helper(node1, edges, v1, 0);
        vis.assign(n, 0);
        helper(node2, edges, v2, 0);

        int idx = -1;
        int min_max_dist = INT_MAX;
        for(int i=0; i<n; i++){
            // cout << i << " " << v1[i] << " " << v2[i] << endl;
            if(v1[i] != -1 && v2[i] != -1){
                if(min_max_dist > max(v1[i], v2[i])){
                    min_max_dist = max(v1[i], v2[i]);
                    idx = i;
                }
            }
        }

        return idx;
    }
};