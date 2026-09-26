class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0;
        int low = 0;
        int high = nums.size();
        while(low < high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                pos = mid+1;
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return pos;
    }
};