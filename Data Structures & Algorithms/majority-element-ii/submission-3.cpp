class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1 = 0, elem2 = 0;
        int count1 = 0, count2 = 0;
        for(int n:nums){
            if(n == elem1)
                count1++;
            else if(n == elem2)
                count2++;
            else if(count1 == 0){
                count1 = 1;
                elem1 = n;
            }
            else if(count2 == 0){
                count2 = 1;
                elem2 = n;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(int n:nums){
            if(n == elem1)
                count1++;
            if(n == elem2)
                count2++;
        }

        int n = nums.size()/3;
        if(count1 > n){
            if(count2 > n) return {elem1, elem2};
            else return {elem1};
        }
        else{
            if(count2 > n) return {elem2};
            else return {};
        }
        return {};
    }
};