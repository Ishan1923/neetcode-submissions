class Solution {
public:

    /* crying while solving this */

    //M1
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


    // M2 - check this first, might not work
    // In this method it was easy to derive the formula to calculate area that is nums[i] *(left_valid[i] + 
    // right_valid[i] - 1), but calculating left_valid and right_valid was it self complex.
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int> left(n), right(n);

    //     // left[i] = index of nearest strictly-smaller bar to the left, or -1
    //     for (int i = 0; i < n; i++) {
    //         int p = i - 1;
    //         while (p >= 0 && heights[p] >= heights[i]) {
    //             p = left[p] - 1;   // jump past the whole taller run in one step
    //         }
    //         left[i] = p;
    //     }

    //     // right[i] = index of nearest strictly-smaller bar to the right, or n
    //     for (int i = n - 1; i >= 0; i--) {
    //         int p = i + 1;
    //         while (p < n && heights[p] >= heights[i]) {
    //             p = right[p] + 1;  // jump past the whole taller run in one step
    //         }
    //         right[i] = p;
    //     }

    //     int maxArea = 0;
    //     for (int i = 0; i < n; i++) {
    //         int width = right[i] - left[i] - 1;
    //         maxArea = max(maxArea, heights[i] * width);
    //     }
    //     return maxArea;
    // }
};
