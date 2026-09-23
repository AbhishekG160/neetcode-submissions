class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem = 0;
        for(int i:nums){
            if(count == 0)
                elem = i;
            count += (i == elem)?1:-1;
        }
        return elem;
    }
};