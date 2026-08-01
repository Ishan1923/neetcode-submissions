class Solution {
public:
    bool isPalindrome(string s_) {

        string s = "";

        for(const char& c : s_){
            if((c >= 48 && c <= 57) || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                s += (c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c);
        }

        for(auto c : s) cout << c;

        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }
};
