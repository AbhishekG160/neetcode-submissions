class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(char& c:tasks)
            freq[c]++;
        
        priority_queue<int> maxh; // frequency
        queue<pair<int, int>> q; // remain freq , time when available
        int timer = 0;
        for(auto& pair:freq)
            maxh.push(pair.second);

        while(!q.empty() || !maxh.empty()){
            timer++;
            if(!maxh.empty()){
                int f = maxh.top();
                maxh.pop();
                if((f-1) > 0)
                    q.push({f-1, timer + n});
            }
            while(!q.empty() && q.front().second <= timer){
                maxh.push(q.front().first);
                q.pop();
            }
        }

        return timer;
    }
};
