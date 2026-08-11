class Solution {
public:

    int rob_houses(int i, const vector<int>& nums, vector<int>& memo){
        int n = nums.size();
        if(i >= n || i < 0) return 0;

        if(memo[i] != -1) return memo[i];

        int rob = rob_houses(i + 2, nums, memo) + nums[i];
        int not_rob = rob_houses(i + 1, nums, memo);

        return memo[i] = max(rob, not_rob);

    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> memo(n, -1);
        
        return rob_houses(0, nums, memo);
    }
};
