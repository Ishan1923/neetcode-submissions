class Solution {
public:

    int f(int curr, int prev, int len, const vector<int>& nums, vector<vector<int>>& memo){
        int n = nums.size();
        if(curr == n) return len;

        if(memo[curr][len] != -1) return memo[curr][len];

        int take = 0, notTake = 0;

        notTake = f(curr + 1, prev, len, nums, memo);

        if(prev == -1 || nums[curr] - nums[prev] == 1){
            take = f(curr + 1, curr, (prev == -1 ? 1 : len + 1), nums, memo);
        }

        return memo[curr][len] = max(take, notTake);

    }

    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        
        return f(0, -1, 0, nums, memo);


    }
};
