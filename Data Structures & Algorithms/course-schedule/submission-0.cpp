class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for(auto prereq:prerequisites){
            int course = prereq[0];
            int depen = prereq[1];
            adj[depen].push_back(course);
            indeg[course]++;
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
            for(auto next:adj[course]){
                indeg[next]--;
                if(indeg[next] == 0)
                    q.push(next);
            }
        }
        return completed == numCourses;
    }
};
