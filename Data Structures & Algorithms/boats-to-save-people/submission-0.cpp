class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int boats = 0;
        int i=0, j=n-1;
        sort(people.begin(), people.end());
        while(i<=j){
            if(people[i]+people[j] <= limit){
                i++;
                j--;
                boats++;
            }
            else{
                j--;
                boats++;
            }
        }
        return boats;
    }
};