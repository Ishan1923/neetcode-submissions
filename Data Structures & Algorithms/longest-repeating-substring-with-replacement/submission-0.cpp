class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int mx_freq = 0;
        int mx_len = 0;
        vector<int> freq(26, 0);
        int l = 0, r = 0;

        while(r < n){
            freq[s[r] - 'A']++;

            mx_freq = max(mx_freq, freq[s[r] - 'A']);

            int winlen = r - l + 1;
            while(winlen - mx_freq > k){
                freq[s[l] - 'A']--;
                l++;
                winlen = r - l + 1;
            }

            mx_len = max(mx_len, winlen);

            r++;
        }

        return mx_len;
    }
};
