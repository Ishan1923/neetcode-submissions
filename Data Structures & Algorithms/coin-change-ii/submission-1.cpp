class Solution {
public:

    int f(int ind, int target, const vector<int>& coins, vector<vector<int>>& memo){

        if(target == 0) return 1;

        if(ind < 0) return 0;

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

        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));

        return f(n - 1, amount, coins, memo);
    }
};
