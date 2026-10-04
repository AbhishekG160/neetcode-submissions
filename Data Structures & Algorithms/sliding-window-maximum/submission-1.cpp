class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> result;

        // push the elem into pq 
        // remove all the indices if it has index less than the index-window size 
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
            if(i+1 >= k){
                while(pq.top().second <= i-k)
                    pq.pop();
                result.push_back(pq.top().first);
            }
        }
        return result;
    }
};
