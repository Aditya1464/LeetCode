class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto &pre : prerequisites){
            edges[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0; i<numCourses; i++){ 
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for(auto ed : edges[front]){
                inDegree[ed]--;
                if(inDegree[ed] == 0) q.push(ed);
            }
        }

        reverse(ans.begin(), ans.end());
        if(ans.size() != numCourses) return {};
        return ans;
    }
};