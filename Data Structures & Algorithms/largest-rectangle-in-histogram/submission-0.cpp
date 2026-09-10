class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        stack<int> st;
        for(int i=0; i<=heights.size(); i++){
            int h = (i<heights.size())?(heights[i]):0;
            while(!st.empty() && h<heights[st.top()]){    
                int idx = st.top();
                st.pop();
                int width = i- ((st.empty())? -1:st.top()) -1;
                int height = heights[idx];
                int area = width*height;
                maxarea = max(maxarea, area);
            }
            st.push(i);
        }
        return maxarea;
    }
};
