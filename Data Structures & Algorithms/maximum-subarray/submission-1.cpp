class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // KADANE'S ALGORITHM -> LOcal AVG AND GLOBAL AVG

        int global_mx = nums[0]; // max so far......
        int curr_mx = nums[0]; // curr max

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            curr_mx = max(curr_mx + num, num);
            global_mx = max(global_mx, curr_mx);
        }

        return global_mx;

    }
};
