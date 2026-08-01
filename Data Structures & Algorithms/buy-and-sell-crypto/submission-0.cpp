class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, mx = INT_MIN;

        int n = prices.size();

        for(int i = 0; i < n; i++){
            mn = min(mn, prices[i]);
            mx = max(mx, prices[i] - mn);
        }

        return mx;

    }
};
