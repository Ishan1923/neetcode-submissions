class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        if(n <= 1) return n;

        int l = 0, r = 0;

        vector<int> seen(128, 0);

        int mx_len = 0;

        while(r < n){

            seen[s[r]]++;

            while(seen[s[r]] > 1){
                seen[s[l]]--;
                l++;
            }

            int len = r - l + 1;
            mx_len = max(mx_len, len);

            r++;
        }
        return mx_len;
        
    }
};
