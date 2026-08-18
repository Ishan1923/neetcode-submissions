class Solution {
public:

    int f(int ind, int canBuy, const vector<int>& prices, vector<vector<int>>& memo){
        int n = prices.size();
        if(ind >= n) return 0;

        if(memo[ind][canBuy] != INT_MIN) return memo[ind][canBuy];

        int buy = INT_MIN, sell = INT_MIN, doNothing = INT_MIN;

        if(canBuy){
            buy = f(ind + 1, 0, prices, memo) - prices[ind];
        }   
        else{
            sell = f(ind + 2, 1, prices, memo) + prices[ind];
        }

        doNothing = f(ind + 1, canBuy, prices, memo);

        return memo[ind][canBuy] = max(buy, max(sell, doNothing));

    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> memo(n, vector<int>(2, INT_MIN));

        int profit = f(0, 1, prices, memo);
        return profit >= 0 ? profit : 0;
    }
};
