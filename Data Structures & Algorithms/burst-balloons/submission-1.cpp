class Solution {
public:
    
    int f(int i, int j, const vector<int>& nums, vector<vector<int>>& memo){
        if(i > j) return 0;
        if(memo[i][j] != -1 ) return memo[i][j];

        int mx = INT_MIN;

        for(int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1];
            coins = coins + f(i, k - 1, nums, memo) + f(k + 1, j, nums, memo);
            mx = max(mx, coins);
        }
        return memo[i][j] = mx;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return f(1, n, nums, memo);
    }
};
