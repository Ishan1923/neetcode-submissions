class Solution {
public:

    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        if(n == 0) return 0;

        int global_mn = nums[0];
        int global_mx = nums[0];
        int res = global_mx;

        for(int i = 1; i < n; i++){ //O(n)
            
            if(nums[i] < 0){
                swap(global_mn, global_mx);
            }

            global_mx = max(nums[i], nums[i] * global_mx);
            global_mn = min(nums[i], nums[i] * global_mn);

            res = max(res, global_mx);

        }

        return res;

    }
};
