class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cap(1001, 0);
        for(auto trip:trips){
            cap[trip[1]] += trip[0];
            cap[trip[2]] -= trip[0];
        }
        int people = 0;
        for(int i:cap){
            people += i;
            if(people > capacity)
                return false;
        }
        return true;
    }
};