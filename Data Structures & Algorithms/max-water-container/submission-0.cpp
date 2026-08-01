class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int ar = 0;

        while(l < r){
            int curr_ar = (r - l) * min(heights[l], heights[r]);
            ar = max(ar, curr_ar);
            if(heights[l] < heights[r]) l++;
            else r--;
        }

        return ar;
    }
};
