class Solution {
public:

    int count(int i, const vector<int>& cost, vector<int>& memo){
        int n = cost.size();
        if(i >= n) return 0;

        if(memo[i] != -1) return memo[i];
        
        int step1 = count(i + 1, cost, memo) + cost[i];
        int step2 = count(i + 2, cost, memo) + cost[i];

        return memo[i] = min(step1, step2);

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        count(0, cost, memo);
        return min(memo[0], memo[1]);
    }
};
