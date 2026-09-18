class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        vector<int> result;
        for(auto& prereq:prerequisites){
            adj[prereq[1]].push_back(prereq[0]);
            // dependency --> course // need to do depen before the course
            indeg[prereq[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(indeg[i] == 0)
                q.push(i);

        int completed = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            completed++;
            result.push_back(course);
            for(auto& next:adj[course]){
                indeg[next]--;
                if(indeg[next] == 0)
                    q.push(next);
            }
        }
        return (completed==numCourses)?result:vector<int>{};
    }
};
