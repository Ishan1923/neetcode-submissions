class Solution {
public:


    bool f(int idx, int n, const string& s, const vector<string>& wordDict, vector<int>& memo){
        if(idx == n) return true;

        if(memo[idx] != -1) return memo[idx] == 1 ? true : false;

        bool ans = false;

        for(int i = 0; i < wordDict.size(); i++){
            int len = wordDict[i].size();
            if(idx + len <= n){
                bool flag = true;
                for(int j = 0; j < len; j++){
                    if(wordDict[i][j] != s[idx + j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans |= f(idx + len, n, s, wordDict, memo);
                    if(ans) break;
                }
            }            
        }
        memo[idx] = ans == true ? 1 : 0;
        return ans;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> memo(n, -1);
        return f(0, n, s, wordDict, memo);
    }
};
