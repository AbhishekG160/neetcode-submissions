class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for(int i=0; i<n; i++)
            projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());

        int idx = 0;
        priority_queue<int> maxh;
        for(int i=0; i<k; i++){
            while(idx<n && projects[idx].first <= w)
                maxh.push(projects[idx++].second);
            if(!maxh.empty()){
                w += maxh.top();
                maxh.pop();
            }
        }
        return w;
    }
};