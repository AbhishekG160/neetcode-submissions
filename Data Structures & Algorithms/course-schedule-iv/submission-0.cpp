class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isprereq(numCourses,vector<bool>(numCourses, false));
        for(auto& pre:prerequisites)
            isprereq[pre[0]][pre[1]] = true; // pre0 is prereq for pre1

        for(int k=0; k<numCourses; k++)
            for(int i=0; i<numCourses; i++)
                for(int j=0; j<numCourses; j++)
                    if(isprereq[i][j] == false)
                        isprereq[i][j] = isprereq[i][k] && isprereq[k][j] ;

        vector<bool> result;
        for(auto& query:queries)
            result.push_back(isprereq[query[0]][query[1]]);
        return result;
    }
};