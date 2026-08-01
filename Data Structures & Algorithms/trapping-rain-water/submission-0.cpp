class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix_max = height;
        vector<int> suffix_max = height;

        int left_max = height[0];
        for(int i = 0; i < height.size(); i++){
            left_max = max(left_max, height[i]);
            prefix_max[i] = left_max;
        }

        int right_max = height[n - 1];
        for(int i = n - 1; i >= 0; i--){
            right_max = max(right_max, height[i]);
            suffix_max[i] = right_max;
        }
        
        int total_trapped_water = 0;
        for(int i = 0; i < n; i++){
            int trapped_water_at_i = min(prefix_max[i], suffix_max[i]) - height[i];
            total_trapped_water += trapped_water_at_i;
        }

        return total_trapped_water;

    }
};
