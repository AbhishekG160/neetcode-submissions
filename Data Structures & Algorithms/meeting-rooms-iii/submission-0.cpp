class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> used; 
        // end time, room number
        priority_queue<int, vector<int>, greater<int>> free; 
        // room number
        for(int i=0; i<n; i++)
            free.push(i);
        
        vector<int> count_meets(n, 0);
        for(auto& meet:meetings){
            int start = meet[0];
            int end = meet[1];
            int duration = end-start;

            // free up rooms which ends at the start of current meet
            while(!used.empty() && used.top().first <= start){
                free.push(used.top().second);
                used.pop();
            }

            // find the smallest number room from free rooms -> already available or need wait
            if(!free.empty()){
                // already available
                int rnum = free.top();
                free.pop();
                used.push({end, rnum});
                count_meets[rnum]++;
            }
            else{
                // room not currently available
                auto [earliest_ending , rnum] = used.top();
                used.pop();
                int new_end = duration + earliest_ending;
                used.push({new_end, rnum});
                count_meets[rnum]++;
            }
        }

        // room with the maximum number of meetings done
        int maxm_meets = 0;
        int room_number;
        for(int i=0; i<n; i++){
            if(count_meets[i] > maxm_meets){
                maxm_meets = count_meets[i];
                room_number = i;
            }
        }
        
        return room_number;
    }
};