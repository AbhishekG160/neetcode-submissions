class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<array<int, 3>> taskss;
        // enqueue time , processing time need , index in org
        for(int i=0; i<n; i++)
            taskss.push_back({tasks[i][0], tasks[i][1], i});
        sort(taskss.begin(), taskss.end());
        
        long long timer = 0;
        vector<int> result;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        // processing time , index in org array
        int curridx = 0;

        while(curridx < n || !minh.empty()){
            // currently no task available --> pass time
            if(minh.empty() && taskss[curridx][0]>timer)
                timer = taskss[curridx][0];
            
            // all the tasks that enqueued at the time timer - push into minh
            while(curridx<n && taskss[curridx][0] <= timer){
                minh.push({taskss[curridx][1], taskss[curridx][2]});
                curridx++; 
            }

            // complete the shortest processing time task
            auto [proctime , idx] = minh.top();
            minh.pop();
            result.push_back(idx);
            timer += proctime;
        }

        return result;
    }
};