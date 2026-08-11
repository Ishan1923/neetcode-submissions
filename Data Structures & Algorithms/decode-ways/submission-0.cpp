class Solution {
public:

    int f(int i, const string& s, vector<int>& memo){
        int n = s.size();
        if(i >= n) return 1;

        if(memo[i] != -1) return memo[i];

        int take = 0;    
        int notTake = 0;

        if(s[i] != '0'){
            take = f(i + 1, s, memo);
        }
        if(i + 1 < n && s[i] != '0'){
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(num >= 10 && num <= 26){
                notTake = f(i + 2, s, memo);
            }
        }

        return memo[i] = take + notTake;    

    }

    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return f(0, s, memo);
    }
};
