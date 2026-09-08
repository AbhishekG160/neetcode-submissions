class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int extrafuel = 0; // if (>0) solution must exist else -1
        int currtank = 0;
        int n = gas.size();
        int starter = 0;
        for(int i=0; i<n; i++){
            currtank += gas[i] - cost[i];
            extrafuel += gas[i]-cost[i];
            if(currtank < 0){ // not possible here
                currtank = 0;
                starter = i+1;
            }
        }
        return (extrafuel>=0)?starter:-1;
    }
};
