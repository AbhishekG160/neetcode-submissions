class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // sort(meetings.begin(), meetings.end());
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> used; 
        // // end time, room number
        // priority_queue<int, vector<int>, greater<int>> free; 
        // // room number
        // for(int i=0; i<n; i++)
        //     free.push(i);
        
        // vector<int> count_meets(n, 0);
        // for(auto& meet:meetings){
        //     int start = meet[0];
        //     int end = meet[1];
        //     int duration = end-start;

        //     // free up rooms which ends at the start of current meet
        //     while(!used.empty() && used.top().first <= start){
        //         free.push(used.top().second);
        //         used.pop();
        //     }

        //     // find the smallest number room from free rooms -> already available or need wait
        //     if(!free.empty()){
        //         // already available
        //         int rnum = free.top();
        //         free.pop();
        //         used.push({end, rnum});
        //         count_meets[rnum]++;
        //     }
        //     else{
        //         // room not currently available
        //         auto [earliest_ending , rnum] = used.top();
        //         used.pop();
        //         int new_end = duration + earliest_ending;
        //         used.push({new_end, rnum});
        //         count_meets[rnum]++;
        //     }
        // }

        // // room with the maximum number of meetings done
        // int maxm_meets = 0;
        // int room_number;
        // for(int i=0; i<n; i++){
        //     if(count_meets[i] > maxm_meets){
        //         maxm_meets = count_meets[i];
        //         room_number = i;
        //     }
        // }
        
        // return room_number;

        sort(meetings.begin(), meetings.end());
        // in use -> track (end time) - when it be freed with its (room number)
        // empty room -> track (room number) -> to get the smallest room number
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> in_use;
        priority_queue<int, vector<int>, greater<int>> empty;
        for(int i=0; i<n; i++) empty.push(i);

        // track number of meetings happened in each room
        vector<int> meets(n, 0);

        for(auto& meeting:meetings){
            int start = meeting[0];
            int end = meeting[1];
            int duration = end-start;
            // check if any room gets empmty at the start of this meet
            while(!in_use.empty() && in_use.top().first <= start){
                empty.push(in_use.top().second);
                in_use.pop();
            }
            // assign the current meeting
            if(!empty.empty()){
                // empty room available
                int rnum = empty.top();
                empty.pop();
                in_use.push({end, rnum});
                meets[rnum]++;
            }
            else{
                // room not available - wait till a room gets free
                auto [waiting, rnum] = in_use.top();
                int new_duration = waiting + duration;
                in_use.pop();
                in_use.push({new_duration, rnum});
                meets[rnum]++;
            }
        }

        int max_meets = 0;
        int room = 0;
        for(int i=0; i<n; i++){
            if(max_meets < meets[i]){
                max_meets = meets[i];
                room = i;
            }
        }
        return room;
    }
};