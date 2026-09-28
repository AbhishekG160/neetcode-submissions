/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // peak finding then 2 binary searches
        int n = mountainArr.length();
        int low=0, high=n-1;
        while(low < high){
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))  
                low = mid+1;
            else high = mid;
        }
        int peak = low;

        // binarysearch 1 on the left of peak
        low=0, high=peak;
        while(low <= high){
            int mid = low+(high-low)/2;
            int val = mountainArr.get(mid);
            if(val == target)
                return mid;
            else if(val < target)
                low = mid+1;
            else high = mid-1;
        }

        low = peak+1, high = n-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            int val = mountainArr.get(mid);
            if(val == target) 
                return mid;
            else if(val < target)
                high = mid-1;
            else low = mid+1;
        }
        return -1;
    }  
};