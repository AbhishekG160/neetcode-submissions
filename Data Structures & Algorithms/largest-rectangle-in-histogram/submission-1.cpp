class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // int maxarea = 0;
        // stack<int> st;
        // for(int i=0; i<=heights.size(); i++){
        //     int h = (i<heights.size())?(heights[i]):0;
        //     while(!st.empty() && h<heights[st.top()]){    
        //         int idx = st.top();
        //         st.pop();
        //         int width = i- ((st.empty())? -1:st.top()) -1;
        //         int height = heights[idx];
        //         int area = width*height;
        //         maxarea = max(maxarea, area);
        //     }
        //     st.push(i);
        // }
        // return maxarea;

        int maxarea = 0;
        stack<int> st;
        int n = heights.size();
        for(int i=0; i<=n; i++){
            int newh = (i==n)?0:heights[i];
            while(!st.empty() && newh < heights[st.top()]){
                int toph = heights[st.top()];
                st.pop();
                int left = (!st.empty())?st.top():-1;
                // (i-1) - (left+1) + 1
                int width = i-left-1;
                int area = width*toph;
                maxarea = max(area, maxarea);
            }
            st.push(i);
        }
        return maxarea;
    }
};
