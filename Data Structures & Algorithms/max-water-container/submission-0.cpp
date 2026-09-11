class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n-1;
        int maxwater = 0;
        while(i<j){
            int w = j-i;
            int h = min(heights[i],heights[j]);
            maxwater = max(maxwater, h*w);
            if(heights[i] < heights[j])
                i++;
            else 
                j--;
        }
        return maxwater;
    }
};
