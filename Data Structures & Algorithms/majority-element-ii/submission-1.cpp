class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int, int> freq;
        // for(int& n:nums)
        //     freq[n]++;
        // vector<int> result;
        // int n = nums.size();
        // n = n/3;
        // for(auto& pair:freq)
        //     if(pair.second > n)
        //         result.push_back(pair.first);
        // return result;

        int n1=0, n2=0;
        int count1=0, count2=0;
        for(int& n:nums){
            if(n == n1) count1++;
            else if(n == n2) count2++;
            else if(count1 == 0){
                n1 = n;
                count1 = 1;
            }
            else if(count2 == 0){
                n2 = n;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for(int& n:nums){
            if(n == n1) count1++;
            if(n == n2) count2++;
        }
        int n = nums.size()/3;
        if(count1>n){
            if(count2>n) return {n1, n2};
            else return {n1};
        }
        else{
            if(count2>n) return {n2};
            else return {};
        }
    }
};