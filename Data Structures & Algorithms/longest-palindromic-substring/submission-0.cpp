class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();


        int bestStart = 0;
        int bestLen = 1;

        auto expand = [&](int l, int r){
            while(l >= 0 && r < n && s[l] == s[r]){
                int len = r - l + 1;

                if(len > bestLen){
                    bestLen = len;
                    bestStart = l;
                }

                l--;
                r++;

            }
        };

        for(int i = 0; i < n; i++){
            expand(i, i);
            expand(i, i + 1);
        }

        return s.substr(bestStart, bestLen);

    }
};
