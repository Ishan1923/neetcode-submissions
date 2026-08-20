class Solution {
public:

    int f(int ind1, int ind2, const string& word1, const string& word2, vector<vector<int>>& memo){

        if(ind1 < 0 && ind2 < 0) return 0;
        if(ind1 < 0) return ind2 + 1;
        if(ind2 < 0) return ind1 + 1;


        if(memo[ind1][ind2] != -1) return memo[ind1][ind2];

        if(word1[ind1] == word2[ind2]) return f(ind1 - 1, ind2 - 1, word1, word2, memo);

        int insert = 1 + f(ind1, ind2 - 1, word1, word2, memo);

        int del = 1 + f(ind1 - 1, ind2, word1, word2, memo);

        int replace = 1 + f(ind1 - 1, ind2 - 1, word1, word2, memo);

        return memo[ind1][ind2] = min(insert, min(del, replace));

    }

    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        return f(n - 1, m - 1, word1, word2, memo);

    }
};
