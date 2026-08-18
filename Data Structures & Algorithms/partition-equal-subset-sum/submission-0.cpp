class Solution {
public:

    bool f(int ind, int target, const vector<int>& nums, vector<vector<int>>& memo){

        if(target == 0) return true;

        if(ind == 0) return nums[0] == target;

        if(memo[ind][target] != -1) return memo[ind][target];

        bool take = (target < nums[ind]) ? false : f(ind - 1, target - nums[ind], nums, memo);
        bool notTake = f(ind - 1, target, nums, memo);

        return memo[ind][target] = (take | notTake) ? 1 : 0;

    }


    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalSum = 0;

        for(const auto& num : nums) totalSum += num;
        
        if(totalSum % 2) return false;

        int target = totalSum / 2;

        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        return f(n - 1, target, nums, memo);

    }
};
