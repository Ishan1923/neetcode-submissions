class Solution {
public:

    /* crying while solving this */

    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;

        int n = heights.size();

        int mx_area = 0;

        for(int i = 0; i <= n; i++){
            int currHeight = (i == n) ? 0 : heights[i];

            while(!st.empty() && heights[st.top()] >= currHeight){
                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;

                int area = height * width;

                mx_area = max(mx_area, area);
            }

            st.push(i);
        }

        return mx_area;

    }
};
