class Solution {
public:


    int f(int ind, int target, const vector<int>& nums, vector<vector<int>>& memo, const int& offset){

        if(abs(target) > offset) return 0;

        if(ind < 0) return target == 0 ? 1 : 0 ;

        int shifted = target + offset;
        if(memo[ind][shifted] != -1) return memo[ind][shifted];

        int add = 0, sub = 0;

        add = f(ind - 1, target - nums[ind], nums, memo, offset);
        sub = f(ind - 1, target + nums[ind], nums, memo, offset);

        return memo[ind][shifted] = add + sub;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();

        int sum = 0;
        for(const auto& num : nums) sum += num;

        if(abs(target) > sum) return 0;

        vector<vector<int>> memo(n, vector<int>(2 * abs(sum) + 1, -1));

        return f(n - 1, target, nums, memo, sum);
    
    
    }


};
