class Solution {
public:

    int f(int left_amount, const vector<int>& coins, vector<int>& memo){
        if(left_amount == 0) return 0;
        if(left_amount < 0) return -1;

        if(memo[left_amount] != -2) return memo[left_amount];

        int mn = INT_MAX;

        for(auto& coin : coins){
            int res = f(left_amount - coin, coins, memo);
            if(res >= 0){
                mn = min(mn, res + 1);
            }
        }

        memo[left_amount] = mn == INT_MAX ?  -1 : mn;

        return memo[left_amount];

    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2);
        return f(amount, coins, memo);
    }
};
