class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for(int first = 0; first<n-3; first++){
            if(first>0 && nums[first]==nums[first-1])
                continue;
            if((long long)nums[first]+nums[first+1]+nums[first+2]+nums[first+3] > t)
                continue;
            if((long long)nums[first]+nums[n-1]+nums[n-2]+nums[n-3] < t)
                continue;

            for(int second = first+1; second<n-2; second++){
                if(second>first+1 && nums[second]==nums[second-1])
                    continue;
                if((long long)nums[first]+nums[second]+nums[second+1]+nums[second+2] > t)
                    continue;
                if((long long)nums[first]+nums[second]+nums[n-1]+nums[n-2] < t)
                    continue;

                int i = second+1, j = n-1;
                while(i<j){
                    long long sum = (long long)nums[first]+nums[second]+nums[i]+nums[j];
                    if(sum == t){
                        result.push_back({ nums[first],nums[second],nums[i],nums[j]});
                        while(i<j && nums[i]==nums[i+1]) i++;
                        while(i<j && nums[j]==nums[j-1]) j--;
                        i++;
                        j--;
                    }
                    else if(sum < t) i++;
                    else j--;
                }
            }
        }
        return result;
    }
};