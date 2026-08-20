class Solution {
public:


    int f(int ind1, int ind2, const string& s, const string& t, vector<vector<int>>& memo){
        if(ind2 == t.size()) return 1;
        if(ind1 == s.size()) return 0;

        if(memo[ind1][ind2] != -1) return memo[ind1][ind2];


        int subsequences = 0;

        if(s[ind1] == t[ind2]){
            subsequences += (f(ind1 + 1, ind2, s, t, memo) + f(ind1 + 1, ind2 + 1, s, t, memo));
        }
        else{
            subsequences += f(ind1 + 1, ind2, s, t, memo);
        }

        return memo[ind1][ind2] = subsequences;


    }

    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<int>> memo(n, vector<int>(m, -1));
        

        return f(0, 0, s, t, memo);

    }
};
