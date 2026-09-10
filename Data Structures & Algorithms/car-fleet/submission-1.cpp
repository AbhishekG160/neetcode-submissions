class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) 
            return 0;
        vector<pair<int, double>> cars(n);
        // pos, time
        for (int i=0; i<n; ++i) {
            double time = (double)(target-position[i]) / speed[i];
            cars[i] = {position[i], time};
        }

        sort(cars.rbegin(), cars.rend());
        // higher position -> ahead of other -> cars behind will have upper bound 

        double time_of_car_ahead = 0.0;
        int fleets = 0;
        for(auto& [pos , time]:cars){
            if(time > time_of_car_ahead){ // cant become one with the fleet ahead
                time_of_car_ahead = time;
                fleets++;
            }
        }
        return fleets;
    }
};
