class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();

        int counter = 0;

        auto expand = [&](int l, int r){
            while(l >= 0 && r < n && s[l] == s[r]){
                
                counter++;

                l--;
                r++;

            }
        };

        for(int i = 0; i < n; i++){
            expand(i, i);
            expand(i, i + 1);
        }

        return counter;
        
    }
};
