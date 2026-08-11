class Solution {
public:

    int rob_house(int i, const vector<int>& nums, vector<int>& memo, const int& n){
        if(i >= n) return 0;

        if(memo[i] != - 1) return memo[i];
        
        int rob = rob_house(i + 2, nums, memo, n) + nums[i];

        int not_rob = rob_house(i + 1, nums, memo, n);

        return memo[i] = max(rob, not_rob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0]; 
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> memo1(n, -1);
        vector<int> memo2(n, -1);

        return max(rob_house(0, nums, memo1, n - 1), rob_house(1, nums, memo2, n));

    }
};
