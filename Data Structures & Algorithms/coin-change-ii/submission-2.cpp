class Solution {
public:

    int f(int ind, int target, const vector<int>& coins, vector<vector<int>>& memo){

        if(target == 0) return 1; //base case
 
        if(ind < 0) return 0; // edge case

        if(memo[ind][target] != -1) return memo[ind][target];

        int take = 0, notTake = 0;

        notTake = f(ind - 1, target, coins, memo);

        if(target >= coins[ind]){
            take = f(ind, target - coins[ind], coins, memo);
        }


        return memo[ind][target] = take + notTake;


    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        // vector<vector<int>> memo(n, vector<int>(amount + 1, -1));

        // return f(n - 1, amount, coins, memo);

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for(int i = 0; i < n; i++) dp[i][0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = 1; j <= amount; j++){
                
                int take = 0, notTake = 0;

                notTake = (i - 1 < 0) ? notTake : dp[i - 1][j];

                take = (j - coins[i] < 0) ? take : dp[i][j - coins[i]];

                dp[i][j] = take + notTake;

            }
        }

        return dp[n - 1][amount];

    }
};
