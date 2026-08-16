class Solution {
public:


    int f(int idx, int prev_idx, const vector<int>& nums, vector<vector<int>>& memo){
        int n = nums.size();
        if(idx == n) return 0;

        if(memo[idx][prev_idx + 1] != -1) return memo[idx][prev_idx + 1];

        int len = f(idx + 1, prev_idx, nums, memo);
        if(prev_idx == -1 || nums[prev_idx] < nums[idx]){
            len = max(len, 1 + f(idx + 1, idx, nums, memo));
        }

        return memo[idx][prev_idx + 1] = len;

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));

        return f(0, -1, nums, memo);

    }
};
