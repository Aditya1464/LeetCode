#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        vector<bool> viz(n, 0);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        viz[source]=1;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            if (v==destination) return 1;
            for(int u: adj[v]){
                if (!viz[u]){
                    q.push(u);
                    viz[u]=1;
                }
            }
        }
        return 0;
    }
};



// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
//     }
// };









// class Solution {
// public:
//     bool helper(vector<vector<int>> edges, int source, int destination, vector<bool>& visit){

//         for(int i = 0; i < edges.size(); i++){
//             if(visit[i]) continue;

//             if(edges[i][0] == source){
//                 visit[i] = 1;
//                 if(edges[i][1] == destination){
//                     return true;
//                 }
//                 else{
//                     if(helper(edges, edges[i][1], destination, visit)) return true;
//                 }
//             }
//             else if(edges[i][1] == source){
//                 visit[i] = 1;
//                 if(edges[i][0] == destination){
//                     return true;
//                 }
//                 else{
//                     if(helper(edges, edges[i][0], destination, visit)) return true;
//                 }
//             }
//             // visit[i] = 0;
//         }

//         return false;
//     }

//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         if(source == destination) return true;
        
//         vector<bool> visit(edges.size(), false);
//         return helper(edges, source, destination, visit);
//     }
// };