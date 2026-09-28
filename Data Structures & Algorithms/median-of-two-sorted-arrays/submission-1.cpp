class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // binary search on the index i in nums 1 
        // iter j will be determined according to the index i --> elements in left half = elements in right half
        //          with a possible difference of 1 if total elements are odd
        // nums1 m and nums2 n --> j+i = (n+m+1)/2
        int m=nums1.size(), n=nums2.size();
        if(m>n) 
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = m;
        // taking high as m --> all the elements of nums1 is in the left partition
        while(low <= high){
            int part1 = low+(high-low)/2;  // gets the 1 extra elem
            // start of the right side of nums1
            int part2 = (m+n+1)/2 - part1;
            
            int leftmax1 = (part1 == 0)? INT_MIN:nums1[part1-1];
            int rightmin1 = (part1 == m)? INT_MAX:nums1[part1];
            int leftmax2 = (part2 == 0)? INT_MIN:nums2[part2-1];
            int rightmin2 = (part2 == n)? INT_MAX:nums2[part2];

            if(leftmax1 <= rightmin2 && leftmax2 <= rightmin1){ // valid
                // check if total elems are odd or even
                if((m+n) %2 == 1)
                    return max(leftmax1, leftmax2);
                else return (max(leftmax1, leftmax2) + min(rightmin1, rightmin2))/2.0;
            }
            else if(leftmax1 > rightmin2)
                high = part1-1;
            else low = part1+1;
        }
        return 0.0;
    }
};
