class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) 
            return 0;
        int left = 0, right = n-1;
        int maxl = 0, maxr = 0;
        int water = 0;
        while(left<right){
            if(height[left] <= height[right]){
                if(height[left] > maxl)
                    maxl = height[left];
                else water += maxl-height[left];
                left++;
            }else{
                if(height[right] > maxr)
                    maxr = height[right];
                else water += maxr - height[right];
                right--;
            }
        }
        return water;
    }
};
