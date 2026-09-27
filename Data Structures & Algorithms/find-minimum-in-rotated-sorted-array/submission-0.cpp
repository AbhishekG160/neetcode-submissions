class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = INT_MAX;
        int low=0, high=nums.size()-1;
        while(low <= high){
            if(nums[low] < nums[high]){
                res = min(res, nums[low]);
                break;
            }
            int mid = low+(high-low)/2;
            res = min(res, nums[mid]);
            if(nums[mid] >= nums[low]){ // sorted on the left
                low = mid+1;
            }
            else high = mid-1;
        }
        return res;
    }
};
