class Solution {
public:

    int count(int stair, const int& n, vector<int>& memo){
        if(stair == n){
            return 1;
        }
        if(stair > n) return 0;

        if(memo[stair] != -1) return memo[stair];

        int step1 = count(stair + 1, n, memo);

        int step2 = count(stair + 2, n, memo);

        return memo[stair] = step1 + step2;

    }


    int climbStairs(int n) {
        vector<int> memo(n, -1); 
        return count(0, n, memo);
    }
};
