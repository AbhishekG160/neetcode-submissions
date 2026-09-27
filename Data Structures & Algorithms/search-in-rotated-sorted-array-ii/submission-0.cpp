class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low+(high - low)/2;
            if(nums[mid] == target)
                return true;

            // stuck due to duplicates
            if(nums[low] == nums[high] && nums[low] == nums[mid]){
                low++;
                high--;
                continue;
            }

            if(nums[low]<=nums[mid]){
                // sorted on left
                if(target>=nums[low] && target<nums[mid])
                    high = mid-1;
                else low = mid+1;
            }
            else{
                // sorted on right
                if(target>nums[mid] && target<=nums[high])
                    low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};